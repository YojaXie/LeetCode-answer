#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<map>

using namespace std;


 // Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode*> res;
        map<vector<int64_t>, TreeNode*> buffer;
        GetCurrentVal(root, buffer, res);
        return res;
    }
    void inOrder(TreeNode* root, vector<int64_t>& NodeVal)
    {
        if (!root)
        {
            NodeVal.push_back(INT64_MIN);
            return;
        }
        inOrder(root->left, NodeVal);
        NodeVal.push_back(root->val);
        inOrder(root->right, NodeVal);
    }
    void GetCurrentVal(TreeNode* root, map<vector<int64_t>, TreeNode*>& buffer, vector<TreeNode*>& res)
    {
        if (!root) return;
        vector<int64_t> NodeVal;
        inOrder(root, NodeVal);
        if (buffer.count(NodeVal) > 0)
            res.push_back(root);
        else
            buffer[NodeVal] = root;
        GetCurrentVal(root->left, buffer, res);
        GetCurrentVal(root->right, buffer, res);
    }
};