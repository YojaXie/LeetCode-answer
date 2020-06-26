/*
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        queue<TreeNode*> buffer;
        buffer.push(root);
        while (!buffer.empty())
        {
            int bufferSize = buffer.size();
            vector<int> rootNodeVal;
            for (int i = 0; i < bufferSize; i++)
            {
                TreeNode* Node = buffer.front();
                buffer.pop();
                if (Node)
                {
                    rootNodeVal.push_back(Node->val);
                    buffer.push(Node->left);
                    buffer.push(Node->right);
                }
            }
            if (!rootNodeVal.empty()) res.push_back(rootNodeVal);
        }
        return res;
    }
};
