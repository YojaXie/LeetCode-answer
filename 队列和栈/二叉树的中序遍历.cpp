/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

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
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> buffer;
        vector<int> res;
        TreeNode* temp = root;
        while (temp || !buffer.empty())
        {
            while (temp)
            {
                buffer.push(temp);
                temp = temp->left;
            }
            temp = buffer.top();
            buffer.pop();
            res.push_back(temp->val);
            temp = temp->right;
        }
        return res;
    }
};