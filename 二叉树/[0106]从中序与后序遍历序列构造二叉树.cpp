/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (inorder.empty()) return NULL;
        return CreateTree(inorder, postorder, 0, postorder.size() - 1, 0, postorder.size() - 1); 
    }

    TreeNode* CreateTree(vector<int>& inorder, vector<int>& postorder, int CurrentRootNodeIndex, int LastRootNodeIndexPost, int LeftInterval, int RightInterval)
    {
        TreeNode* root = new TreeNode(postorder[LastRootNodeIndexPost]);
        if (LeftInterval < RightInterval)
        {
            int RootNodeIndexIn = 0;
            while (inorder[RootNodeIndexIn] != postorder[LastRootNodeIndexPost]) RootNodeIndexIn++;
            if (RootNodeIndexIn > LeftInterval)
                root->left = CreateTree(inorder, postorder, CurrentRootNodeIndex, LastRootNodeIndexPost - RightInterval + RootNodeIndexIn - 1, LeftInterval, RootNodeIndexIn - 1);
            if (RootNodeIndexIn < RightInterval)
                root->right = CreateTree(inorder, postorder, CurrentRootNodeIndex, LastRootNodeIndexPost - 1, RootNodeIndexIn + 1, RightInterval);

        }
        return root;
    }
};