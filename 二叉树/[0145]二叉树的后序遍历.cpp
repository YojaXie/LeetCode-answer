/*
����һ������������������ ���� ������

ʾ��:

����: [1,null,2,3]
   1
    \
     2
    /
   3

���: [3,2,1]
����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
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