/*
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> buffer;
        vector<int> res;
        buffer.push(root);
        while (!buffer.empty())
        {
            TreeNode* TreeRootNode = buffer.top();
            buffer.pop();
            if (TreeRootNode)
            {
                res.push_back(TreeRootNode->val);
                buffer.push(TreeRootNode->left);
                buffer.push(TreeRootNode->right);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};