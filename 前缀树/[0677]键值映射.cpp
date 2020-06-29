/*
ʵ��һ�� MapSum ���������������insert �� sum��
���ڷ��� insert���㽫�õ�һ�ԣ��ַ������������ļ�ֵ�ԡ��ַ�����ʾ����
������ʾֵ��������Ѿ����ڣ���ôԭ���ļ�ֵ�Խ���������µļ�ֵ�ԡ�
���ڷ��� sum���㽫�õ�һ����ʾǰ׺���ַ���������Ҫ���������Ը�ǰ׺��ͷ�ļ���ֵ���ܺ͡�

ʾ�� 1:
����: insert("apple", 3), ���: Null
����: sum("ap"), ���: 3
����: insert("app", 2), ���: Null
����: sum("ap"), ���: 5
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

class MapSum 
{
private:
	int val;
	unordered_map<char, MapSum*> children;
public:
	/** Initialize your data structure here. */
	MapSum() 
	{
		val = 0;
	}

	void insert(string key, int val) 
	{
		MapSum* root = this;
		for (char character : key)
		{
			if (root->children.find(character) == root->children.end())
			{
				MapSum* NewTrie = new MapSum();
				root->children.insert({ character,NewTrie });
			}
			root = root->children[character];
		}
		root->val = val;
	}

	int sum(string prefix) 
	{
		MapSum* root = this;
		for (char character : prefix)
		{
			if (root->children.find(character) == root->children.end()) return 0;
			else root = root->children[character];
		}
		int PrefixSum = 0;
		queue<MapSum*> buffer;
		buffer.push(root);
		while (!buffer.empty())
		{
			root = buffer.front();
			buffer.pop();
			PrefixSum += root->val;
			for (pair<char, MapSum*> ChildrenNode : root->children) 
				buffer.push(ChildrenNode.second);
		}
		return PrefixSum;
	}
};