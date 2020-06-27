/*
����һ������ǰ�������������������������

ע��:
����Լ�������û���ظ���Ԫ�ء�

���磬����
ǰ����� preorder = [3,9,20,15,7]
������� inorder = [9,3,15,20,7]
�������µĶ�������

    3
   / \
  9  20
    /  \
   15   7
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.empty()) return NULL;
        return createTree(preorder, inorder, 0, 0, preorder.size() - 1);
    }
    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int CurrentRootNodePre, int LeftInterval, int RightInterval)
    {
        TreeNode* root = new TreeNode(preorder[CurrentRootNodePre]);
        if (LeftInterval < RightInterval)
        {
            int CurrentRootNodeIn = 0;
            while (inorder[CurrentRootNodeIn] != preorder[CurrentRootNodePre]) CurrentRootNodeIn++;
            if (CurrentRootNodeIn > LeftInterval)
                root->left = createTree(preorder, inorder, CurrentRootNodePre + 1, LeftInterval, CurrentRootNodeIn - 1);
            if (CurrentRootNodeIn < RightInterval)
                root->right = createTree(preorder, inorder, CurrentRootNodePre + CurrentRootNodeIn - LeftInterval + 1, CurrentRootNodeIn + 1, RightInterval);
        }
        return root;
    }
};