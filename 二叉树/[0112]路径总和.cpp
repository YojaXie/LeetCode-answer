/*
����һ����������һ��Ŀ��ͣ��жϸ������Ƿ���ڸ��ڵ㵽Ҷ�ӽڵ��·��������·�������нڵ�ֵ��ӵ���Ŀ��͡�
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ��:
�������¶��������Լ�Ŀ��� sum = 22��

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
���� true, ��Ϊ����Ŀ���Ϊ 22 �ĸ��ڵ㵽Ҷ�ӽڵ��·�� 5->4->11->2��
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