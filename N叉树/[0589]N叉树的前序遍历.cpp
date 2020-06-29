/*
����һ�� N ������������ڵ�ֵ��ǰ�������

���磬����һ�� 3���� :

������ǰ�����: [1,3,5,6,2,4]��

˵��: �ݹ鷨�ܼ򵥣������ʹ�õ�������ɴ�����?
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