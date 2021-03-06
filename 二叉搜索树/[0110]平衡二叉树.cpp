/*
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:
给定二叉树 [3,9,20,null,null,15,7]

	3
   / \
  9  20
	/  \
   15   7
返回 true 。

示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]

	   1
	  / \
	 2   2
	/ \
   3   3
  / \
 4   4
返回 false 。
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