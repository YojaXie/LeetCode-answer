/*
����һ�������������ĸ��ڵ� root ��һ��ֵ key��ɾ�������������е� key ��Ӧ�Ľڵ㣬
����֤���������������ʲ��䡣���ض������������п��ܱ����£��ĸ��ڵ�����á�

һ����˵��ɾ���ڵ�ɷ�Ϊ�������裺
�����ҵ���Ҫɾ���Ľڵ㣻
����ҵ��ˣ�ɾ������

˵���� Ҫ���㷨ʱ�临�Ӷ�Ϊ O(h)��h Ϊ���ĸ߶ȡ�

ʾ��:
root = [5,3,6,2,4,null,7]
key = 3

	5
   / \
  3   6
 / \   \
2   4   7

������Ҫɾ���Ľڵ�ֵ�� 3���������������ҵ� 3 ����ڵ㣬Ȼ��ɾ������
һ����ȷ�Ĵ��� [5,4,6,2,null,null,7], ����ͼ��ʾ��

	5
   / \
  4   6
 /     \
2       7

��һ����ȷ���� [5,2,6,null,4,null,7]��

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