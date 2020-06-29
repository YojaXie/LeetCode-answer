/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

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