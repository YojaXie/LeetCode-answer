/*
����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

ʾ����
���������� [3,9,20,null,null,15,7]��

    3
   / \
  9  20
    /  \
   15   7
�������������� 3 ��
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