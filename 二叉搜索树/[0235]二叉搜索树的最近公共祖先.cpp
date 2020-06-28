/*
����һ������������, �ҵ�����������ָ���ڵ������������ȡ�
�ٶȰٿ�������������ȵĶ���Ϊ���������и��� T ��������� p��q������������ȱ�ʾΪһ����� x��
���� x �� p��q �������� x ����Ⱦ����ܴ�һ���ڵ�Ҳ���������Լ������ȣ�����

���磬�������¶���������:  root = [6,2,8,0,4,7,9,null,null,3,5]

ʾ�� 1:
����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
���: 6
����: �ڵ� 2 �ͽڵ� 8 ��������������� 6��

ʾ�� 2:
����: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
���: 2
����: �ڵ� 2 �ͽڵ� 4 ��������������� 2, ��Ϊ���ݶ�������������Ƚڵ����Ϊ�ڵ㱾��

˵��:
���нڵ��ֵ����Ψһ�ġ�
p��q Ϊ��ͬ�ڵ��Ҿ������ڸ����Ķ����������С�
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
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
        TreeNode* res = NULL;
        presTraversal(root, p, q, res);
        return res;
	}

    void presTraversal(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& res)
    {
        if (!root) return;
        if ((root->val - p->val) * (root->val - q->val) <= 0) res = root;
        else if (root->val < p->val && root->val < q->val) presTraversal(root->right, p, q, res);
        else presTraversal(root->left, p, q, res);
    }
};