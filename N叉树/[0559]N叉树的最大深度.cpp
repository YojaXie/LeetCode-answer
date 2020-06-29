/*
给定一个 N 叉树，找到其最大深度。
最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
例如，给定一个 3叉树 :

我们应返回其最大深度，3。

说明:
树的深度不会超过 1000。
树的节点总不会超过 5000。
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;


// Definition for a Node.
class Node
{
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution 
{
public:
	int maxDepth(Node* root) 
	{
		int res = 0;
		if (!root) return res;
		topDown(root, 1, res);
		return res;
	}

	void topDown(Node* root, int CurrentDepth, int& MaxDepth)
	{
		if (root->children.empty())
		{
			MaxDepth = max(MaxDepth, CurrentDepth);
			return;
		}
		for (Node* ChildrenNode : root->children)
		{
			topDown(ChildrenNode, CurrentDepth + 1, MaxDepth);
		}
	}
};