/*
给定一个 N 叉树，返回其节点值的前序遍历。

例如，给定一个 3叉树 :

返回其前序遍历: [1,3,5,6,2,4]。

说明: 递归法很简单，你可以使用迭代法完成此题吗?
*/

#include<iostream>
#include<vector>
#include<stack>
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
	vector<int> preorder(Node* root) 
	{
		vector<int> res;
		if (!root) return res;
		stack<Node*> buffer;
		buffer.push(root);
		while (!buffer.empty())
		{
			Node* RootNode = buffer.top();
			buffer.pop();
			if (RootNode)
			{
				res.push_back(RootNode->val);
				for (int i = RootNode->children.size() - 1; i >= 0; i--) buffer.push(RootNode->children[i]);
			}
		}
		return res;
	}
};