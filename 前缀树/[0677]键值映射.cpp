/*
实现一个 MapSum 类里的两个方法，insert 和 sum。
对于方法 insert，你将得到一对（字符串，整数）的键值对。字符串表示键，
整数表示值。如果键已经存在，那么原来的键值对将被替代成新的键值对。
对于方法 sum，你将得到一个表示前缀的字符串，你需要返回所有以该前缀开头的键的值的总和。

示例 1:
输入: insert("apple", 3), 输出: Null
输入: sum("ap"), 输出: 3
输入: insert("app", 2), 输出: Null
输入: sum("ap"), 输出: 5
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