/*
����һ�� N �������ҵ��������ȡ�
��������ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�������
���磬����һ�� 3���� :

����Ӧ�����������ȣ�3��

˵��:
������Ȳ��ᳬ�� 1000��
���Ľڵ��ܲ��ᳬ�� 5000��
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