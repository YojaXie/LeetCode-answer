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
#include<ctime>

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
	vector<TreeNode*> generateTrees(int n)
	{
		if (n == 0)
		{
			vector<TreeNode*> res;
			return res;
		}
		return TopDown(1, n);
	}
	vector<TreeNode*> TopDown(int low, int high)
	{
		vector<TreeNode*> Current;
		if (high < low) Current.push_back(NULL);
		for (int i = low; i <= high; i++)
		{
			vector<TreeNode*> LeftRes = TopDown(low, i - 1);
			vector<TreeNode*> RightRes = TopDown(i + 1, high);
			for (int j = 0; j < LeftRes.size(); j++)
			{
				for (int k = 0; k < RightRes.size(); k++)
				{
					TreeNode* CurrentNode = new TreeNode(i);
					CurrentNode->left = LeftRes[j];
					CurrentNode->right = RightRes[k];
					Current.push_back(CurrentNode);
				}
			}
		}
		return Current;
	}
};