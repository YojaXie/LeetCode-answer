/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

示例 1:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

示例 2:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。

说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        bool AllFind = false;
        TreeNode* res = NULL;
        pair<bool, bool>temp = presTraversal(root, p, q, res, AllFind);
        return res;
    }
    pair<bool, bool> presTraversal(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res, bool& AllFind)
    {
        if (!root) return make_pair(false, false);
        pair<bool, bool> LeftRes = { false,false };
        pair<bool, bool> RightRes = { false,false };
        pair<bool, bool> RootRes = { false,false };
        pair<bool, bool> ReturnRes = { false,false };
        LeftRes = presTraversal(root->left, p, q, res, AllFind);
        RightRes = presTraversal(root->right, p, q, res, AllFind);
        if (root->val == p->val) RootRes.first = true;
        if (root->val == q->val) RootRes.second = true;
        if (!AllFind)
        {
            if (LeftRes.first || RightRes.first || RootRes.first) ReturnRes.first = true;
            if (LeftRes.second || RightRes.second || RootRes.second) ReturnRes.second = true;
            if (ReturnRes.first && ReturnRes.second)
            {
                res = root;
                AllFind = true;
            }
        }
        return ReturnRes;
    }
};