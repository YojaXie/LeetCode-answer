/*
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3


但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3


进阶：
你可以运用递归和迭代两种方法解决这个问题吗？
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

// 迭代
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

// 递归
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