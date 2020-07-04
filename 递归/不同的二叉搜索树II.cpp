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
		vector<TreeNode*> res;
		vector<TreeNode*> res;
	}
	vector<TreeNode*> TopDown(int low, int high, vector<TreeNode*>& res, int CurrentNum, int& n)
	{
		if (CurrentNum == n) res.push_back(NULL);
		if (i - 1 < low) return vector<TreeNode*> ().push_back(NULL);
		if (high < i + 1) return vector<TreeNode*>().push_back(NULL);
		CurrentNum++;
		for (i = low; i <= high; i++)
		{
			TreeNode* CurrentNode = new TreeNode(i);
			vector<TreeNode*> LeftRes = CurrentNode(low, i - 1, CurrentNum, n);
			vector<TreeNode*> RightRes = CurrentNode(i+1, high, CurrentNum, n);
			if (j = 0; j < LeftRes.size() * RightRes.size(); j++)
			{
				TreeNode* CurrentNode = new TreeNode(i);
			}
		}
	}
};