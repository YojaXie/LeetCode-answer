/*
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
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
    int maxDepth(TreeNode* root) 
    {
        int res=0;
        MaxDepth(root, 1, res);
        return res;
    }
    void MaxDepth(TreeNode* root, int depth, int& res)
    {
        if (!root) return;
        if (!root->left && !root->right) res = max(depth, res);
        MaxDepth(root->left, depth + 1, res);
        MaxDepth(root->right, depth + 1, res);
    }
};