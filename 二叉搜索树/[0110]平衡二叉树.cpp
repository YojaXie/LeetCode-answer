/*
����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
�����У�һ�ø߶�ƽ�����������Ϊ��
һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������1��

ʾ�� 1:
���������� [3,9,20,null,null,15,7]

	3
   / \
  9  20
	/  \
   15   7
���� true ��

ʾ�� 2:
���������� [1,2,2,3,3,null,null,4,4]

	   1
	  / \
	 2   2
	/ \
   3   3
  / \
 4   4
���� false ��
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
	bool isBalanced(TreeNode* root) 
	{
		bool res = true;
		int MaxDepth = DepthTree(root, res);
		return res;
	}
	int DepthTree(TreeNode* root, bool& IsBalance)
	{
		if (!root) return 0;
		int LeftTreeDepth = DepthTree(root->left, IsBalance);
		int RightTreeDepth = DepthTree(root->right, IsBalance);
		if (abs(LeftTreeDepth - RightTreeDepth) > 1) IsBalance = false;
		return max(LeftTreeDepth, RightTreeDepth) + 1;
	}
};