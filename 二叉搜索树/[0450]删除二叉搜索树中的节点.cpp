/*
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：
首先找到需要删除的节点；
如果找到了，删除它。

说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:
root = [5,3,6,2,4,null,7]
key = 3

	5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

	5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

	5
   / \
  2   6
   \   \
	4   7
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	TreeNode* deleteNode(TreeNode* root, int key) 
	{
		TreeNode* FatherTargetNode = NULL;
		TreeNode* TargetNode = searchBST(root, key, FatherTargetNode);
		bool IsLeft = true;
		if (!TargetNode) return root;
		if (TargetNode == root)
		{
			if (!TargetNode->left && !TargetNode->right) return NULL;
			else if (TargetNode->left && !TargetNode->right) root = TargetNode->left;
			else if (!TargetNode->left && TargetNode->right) root = TargetNode->right;
			else
			{
				TreeNode* SwapNode = TargetNode->right;
				TreeNode* temp = TargetNode;
				while (SwapNode->left)
				{
					temp = SwapNode;
					SwapNode = SwapNode->left;
				}
				if (temp == TargetNode)
				{
					SwapNode->left = TargetNode->left;
					root = SwapNode;
				}
				else
				{
					temp->left = SwapNode->right;
					SwapNode->left = TargetNode->left;
					SwapNode->right = TargetNode->right;
					root = SwapNode;
				}
			}
			return root;
		}

		if (FatherTargetNode->left == TargetNode) IsLeft = true;
		else IsLeft = false;
		if (!TargetNode->left && !TargetNode->right)
		{
			if (IsLeft) FatherTargetNode->left = NULL;
			else FatherTargetNode->right = NULL;
		}
		else if (TargetNode->left && !TargetNode->right)
		{
			if (IsLeft) FatherTargetNode->left = TargetNode->left;
			else FatherTargetNode->right = TargetNode->left;
		}
		else if (!TargetNode->left && TargetNode->right)
		{
			if (IsLeft) FatherTargetNode->left = TargetNode->right;
			else FatherTargetNode->right = TargetNode->right;
		}
		else
		{
			TreeNode* SwapNode = TargetNode->right;
			TreeNode* temp = TargetNode;
			while (SwapNode->left)
			{
				temp = SwapNode;
				SwapNode = SwapNode->left;
			}
			if (temp == TargetNode)
			{
				SwapNode->left = TargetNode->left;
				if (IsLeft) FatherTargetNode->left = SwapNode;
				else FatherTargetNode->right = SwapNode;
			}
			else
			{
				temp->left = SwapNode->right;
				SwapNode->left = TargetNode->left;
				SwapNode->right = TargetNode->right;
				if (IsLeft) FatherTargetNode->left = SwapNode;
				else FatherTargetNode->right = SwapNode;
			}
		}
		return root;
	}
	TreeNode* searchBST(TreeNode* root, int val, TreeNode*& lastroot)
	{
		if (!root) return NULL;
		if (root->val == val) return root;
		else if (root->val > val)
		{
			lastroot = root;
			return searchBST(root->left, val, lastroot);
		}
		else
		{
			lastroot = root;
			return searchBST(root->right, val, lastroot);
		}
	}
};