/*
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 
返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

例如,
给定二叉搜索树:

		4
	   / \
	  2   7
	 / \
	1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

		 4
	   /   \
	  2     7
	 / \   /
	1   3 5
或者这个树也是有效的:

		 5
	   /   \
	  2     7
	 / \
	1   3
		 \
		  4
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
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) 
	{
		TreeNode* NewNode = new TreeNode(val);
		if (!root) return NewNode;
		searchBST(root, val, NewNode);
		return root;
	}
	void searchBST(TreeNode* root, int val, TreeNode* NewNode)
	{
		if (!root) return;
		if (root->val > val)
		{
			if (root->left)  searchBST(root->left, val, NewNode);
			else root->left = NewNode;
		}
		else
		{
			if (root->right)  searchBST(root->right, val, NewNode);
			else root->right = NewNode;
		}
	}
};