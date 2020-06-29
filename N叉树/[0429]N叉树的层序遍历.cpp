/*
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
例如，给定一个 3叉树 :
返回其层序遍历:
[
	 [1],
	 [3,2,4],
	 [5,6]
]

说明:
树的深度不会超过 1000。
树的节点总数不会超过 5000。
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
	vector<vector<int>> levelOrder(Node* root) 
	{
		vector<vector<int>> res;
		if (!root) return res;
		queue<Node*> buffer;
		buffer.push(root);
		while (!buffer.empty())
		{
			int FloorSize = buffer.size();
			vector<int> FloorVal;
			for (int i = 0; i < FloorSize; i++)
			{
				Node* CurrentNode = buffer.front();
				buffer.pop();
				if (CurrentNode)
				{
					FloorVal.push_back(CurrentNode->val);
					for (Node* ChildenNode : CurrentNode->children) buffer.push(ChildenNode);
				}
			}
			res.push_back(FloorVal);
		}
		return res;
	}
};