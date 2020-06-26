/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

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
    bool hasPathSum(TreeNode* root, int sum) 
    {
        bool res = false;
        PathSum(root, sum, 0, res);
        return res;
    }

    void PathSum(TreeNode* root, int targetSum, int currentSum, bool& res)
    {
        if (!root) return;
        if (!root->right && !root->left)
        {
            if (currentSum + root->val == targetSum) res = true;
            return;
        }
        PathSum(root->left, targetSum, currentSum + root->val, res);
        PathSum(root->right, targetSum, currentSum + root->val, res);
    }
};