/*
����һ�������������ĸ��ڵ� root ��һ��ֵ key��ɾ�������������е� key ��Ӧ�Ľڵ㣬
����֤���������������ʲ��䡣���ض������������п��ܱ����£��ĸ��ڵ�����á�

һ����˵��ɾ���ڵ�ɷ�Ϊ�������裺
�����ҵ���Ҫɾ���Ľڵ㣻
����ҵ��ˣ�ɾ������

˵���� Ҫ���㷨ʱ�临�Ӷ�Ϊ O(h)��h Ϊ���ĸ߶ȡ�

ʾ��:
root = [5,3,6,2,4,null,7]
key = 3

	5
   / \
  3   6
 / \   \
2   4   7

������Ҫɾ���Ľڵ�ֵ�� 3���������������ҵ� 3 ����ڵ㣬Ȼ��ɾ������
һ����ȷ�Ĵ��� [5,4,6,2,null,null,7], ����ͼ��ʾ��

	5
   / \
  4   6
 /     \
2       7

��һ����ȷ���� [5,2,6,null,4,null,7]��

	5
   / \
  2   6
   \   \
	4   7
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
	TreeNode* deleteNode(TreeNode* root, int key) 
	{
		TreeNode* TargetNode = searchBST(root, key);
		if (!TargetNode) return root;
		if (!TargetNode->left && !TargetNode->right);
	}
	TreeNode* searchBST(TreeNode* root, int val)
	{
		if (!root) return NULL;
		if (root->left)
		{
			if (root->left->val == val) return root;
		}
		if (root->right)
		{
			if (root->right->val == val) return root;
		}
		if (root->val > val) return searchBST(root->left, val);
		else return searchBST(root->right, val);
	}
};