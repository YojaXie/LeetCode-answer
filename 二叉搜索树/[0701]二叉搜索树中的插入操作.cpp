/*
����������������BST���ĸ��ڵ��Ҫ�������е�ֵ����ֵ��������������� 
���ز��������������ĸ��ڵ㡣 ��֤ԭʼ�����������в�������ֵ��

ע�⣬���ܴ��ڶ�����Ч�Ĳ��뷽ʽ��ֻҪ���ڲ�����Ա���Ϊ�������������ɡ� ����Է���������Ч�Ľ����

����,
��������������:

		4
	   / \
	  2   7
	 / \
	1   3

�� �����ֵ: 5
����Է����������������:

		 4
	   /   \
	  2     7
	 / \   /
	1   3 5
���������Ҳ����Ч��:

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