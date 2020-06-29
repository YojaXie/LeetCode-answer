/*
����һ�� N ������������ڵ�ֵ�ĺ��������

���磬����һ�� 3���� :

������������: [5,6,3,2,4,1].

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
	vector<int> postorder(Node* root) 
	{
		vector<int> res;
		if (!root) return res;
		stack<pair<Node*,bool>> buffer;
		buffer.push({ root,false });
		while (!buffer.empty())
		{
			Node* RootNode = buffer.top().first;
			bool IsUsed = buffer.top().second;
			if (RootNode && !IsUsed)
			{
				buffer.top().second = true;
				for (int i = RootNode->children.size() - 1; i >= 0; i--)
					buffer.push({ RootNode->children[i],false });
			}
			if (IsUsed)
			{
				res.push_back(RootNode->val);
				buffer.pop();
			}
		}
		return res;
	}
};
