/*
��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������
�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��

ʾ��:
������������: [-10,-3,0,5,9],
һ�����ܵĴ��ǣ�[0,-3,9,-10,null,5]�������Ա�ʾ��������߶�ƽ�������������

	  0
	 / \
   -3   9
   /   /
 -10  5
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
	TreeNode* sortedArrayToBST(vector<int>& nums) 
	{
		int LeftInterval = 0, RightInterval = int(nums.size()) - 1;
		TreeNode* res = CreateTree(nums, LeftInterval, RightInterval);
		return res;
	}
	TreeNode* CreateTree(vector<int>& nums, int LeftInterval, int RightInterval)
	{
		if (RightInterval < LeftInterval) return NULL;
		int NodeIndex = LeftInterval + (1 + RightInterval - LeftInterval) / 2;
		TreeNode* NewNode = new TreeNode(nums[NodeIndex]);
		NewNode->left = CreateTree(nums, LeftInterval, NodeIndex - 1);
		NewNode->right = CreateTree(nums, NodeIndex + 1, RightInterval);
		return NewNode;
	}
};