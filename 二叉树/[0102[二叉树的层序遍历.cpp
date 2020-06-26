/*
����һ�������������㷵���䰴 ������� �õ��Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��

ʾ����
��������[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
�������α��������

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
