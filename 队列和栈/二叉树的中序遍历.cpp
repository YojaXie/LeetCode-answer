/*
����һ���������������������� ������

ʾ��:

����: [1,null,2,3]
   1
    \
     2
    /
   3

���: [1,3,2]
����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
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