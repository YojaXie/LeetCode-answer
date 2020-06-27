/*
����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x��
���� x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

���磬�������¶�����:  root = [3,5,1,6,2,0,8,null,null,7,4]

ʾ�� 1:
����: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
���: 3
����: �ڵ� 5 �ͽڵ� 1 ��������������ǽڵ� 3��

ʾ�� 2:
����: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
���: 5
����: �ڵ� 5 �ͽڵ� 4 ��������������ǽڵ� 5����Ϊ���ݶ�������������Ƚڵ����Ϊ�ڵ㱾��

˵��:
���нڵ��ֵ����Ψһ�ġ�
p��q Ϊ��ͬ�ڵ��Ҿ������ڸ����Ķ������С�
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