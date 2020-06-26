/*
����һ����������������Ƿ��Ǿ���ԳƵġ�
���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�

    1
   / \
  2   2
 / \ / \
3  4 4  3


����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

    1
   / \
  2   2
   \   \
   3    3


���ף�
��������õݹ�͵������ַ���������������
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

// ����
class Solution1 
{
public:
    bool isSymmetric(TreeNode* root) 
    {
        stack<TreeNode*> bufferleft;
        stack<TreeNode*> bufferright;
        bufferleft.push(root);
        bufferright.push(root);
        while (bufferleft.empty())
        {
            TreeNode* nodeleft = bufferleft.top();
            TreeNode* noderight = bufferright.top();
            bufferleft.pop();
            bufferright.pop();
            if ((!nodeleft && noderight) || (nodeleft && !noderight)) return false;
            else if (!nodeleft && !noderight) continue;
            else
            {
                if (nodeleft->val != noderight->val) return false;
                bufferleft.push(nodeleft->left);
                bufferleft.push(nodeleft->right);
                bufferright.push(noderight->right);
                bufferright.push(noderight->left);
            }
        }
        return true;
    }
};

// �ݹ�
class Solution2
{
public:
    bool isSymmetric(TreeNode* root)
    {
        bool res = true;
        leftRightCompare(root, root, res);
        return res;
    }

    void leftRightCompare(TreeNode* leftNode, TreeNode* rightNode, bool& res)
    {
        if (res)
        {
            if (!leftNode && !rightNode) return;
            else if ((!leftNode && rightNode) || (leftNode && !rightNode)) res = false;
            else
            {
                if (leftNode->val != rightNode->val) res = false;
                leftRightCompare(leftNode->left, rightNode->right, res);
                leftRightCompare(leftNode->right, rightNode->left, res);
            }
        }
    }
};