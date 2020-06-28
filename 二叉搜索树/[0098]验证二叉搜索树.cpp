/*
����һ�����������ж����Ƿ���һ����Ч�Ķ�����������
����һ��������������������������
�ڵ��������ֻ����С�ڵ�ǰ�ڵ������
�ڵ��������ֻ�������ڵ�ǰ�ڵ������
�������������������������Ҳ�Ƕ�����������

ʾ�� 1:
����:
	2
   / \
  1   3
���: true

ʾ�� 2:
����:
	5
   / \
  1   4
	 / \
	3   6
���: false
����: ����Ϊ: [5,1,4,null,null,3,6]��
	 ���ڵ��ֵΪ 5 �����������ӽڵ�ֵΪ 4 ��
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
	bool isValidBST(TreeNode* root) 
	{
		bool IsOrder = true;
		long int temp = LONG_MIN;
		Inorder(root, IsOrder, temp);
		return IsOrder;
	}
	void Inorder(TreeNode* root, bool& IsOrder, long int& MaxNum)
	{
		if (!root) return;
		if (IsOrder)
		{
			Inorder(root->left, IsOrder, MaxNum) ;
			if (root->val > MaxNum)  MaxNum = root->val;
			else IsOrder = false;
			Inorder(root->right, IsOrder, MaxNum);
		}
	}
};