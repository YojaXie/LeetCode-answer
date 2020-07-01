/*
给定一组唯一的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。

示例 1:
输入: ["abcd","dcba","lls","s","sssll"]
输出: [[0,1],[1,0],[3,2],[2,4]]
解释: 可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]

示例 2:
输入: ["bat","tab","cat"]
输出: [[0,1],[1,0]]
解释: 可拼接成的回文串为 ["battab","tabbat"]
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

class Solution 
{
public:
	class Trie
	{
	public:
		pair<bool,int> IsWord;
		unordered_map<char, Trie*> children;
	public:
		Trie()
		{
			IsWord.first = false;
			IsWord.second = -1;
		}
		void insert(string word,int index)
		{
			Trie* root = this;
			for (char character : word)
			{
				if (root->children.find(character) == root->children.end())
				{
					Trie* NewTrie = new Trie();
					root->children.insert({ character,NewTrie });
				}
				root = root->children[character];
			}
			root->IsWord.first = true;
			root->IsWord.second = index;
		}
	};
public:
	vector<vector<int>> palindromePairs(vector<string>& words) 
	{
		vector<vector<int>> res;
		if (words.empty()) return res;
		Trie* head = new Trie();
		Trie* root = head;
		for (int i = 0; i < words.size(); i++) root->insert(words[i], i);
		for (int j = 0; j < words.size(); j++)
		{
			Trie* root = head;
			string temp = words[j];
			//if (temp.empty())
			//{
			//	for (int i = 0; i < words.size(); i++)
			//	{
			//		if (i == j) continue;
			//		string RemainString = words[i];
			//		string ReverseRemainString = RemainString;
			//		reverse(ReverseRemainString.begin(), ReverseRemainString.end());
			//		if (RemainString == ReverseRemainString)
			//		{
			//			vector<int> pos;
			//			pos.push_back(i);
			//			pos.push_back(j);
			//			res.push_back(pos);
			//			vector<int> pos1;
			//			pos1.push_back(j);
			//			pos1.push_back(i);
			//			res.push_back(pos1);
			//		}
			//	}
			//	continue;
			//}
			reverse(temp.begin(), temp.end());
			int k = 0;
			for (; k < temp.size(); k++)
			{
				if (root->children.find(temp[k]) == root->children.end())
				{
					if (root->IsWord.first && root->IsWord.second != j)
					{
						string RemainString;
						int ki = k;
						while (ki < temp.size())
						{
							RemainString.push_back(temp[ki]);
							ki++;
						}
						string ReverseRemainString = RemainString;
						reverse(ReverseRemainString.begin(), ReverseRemainString.end());
						if (RemainString == ReverseRemainString)
						{
							vector<int> pos;
							pos.push_back(root->IsWord.second);
							pos.push_back(j);
							res.push_back(pos);
						}
					}
					break;
				}
				if (root->IsWord.first && root->IsWord.second !=j)
				{
					string RemainString;
					int ki = k;
					while (ki  < temp.size())
					{
						RemainString.push_back(temp[ki]);
						ki++;
					}
					string ReverseRemainString = RemainString;
					reverse(ReverseRemainString.begin(), ReverseRemainString.end());
					if (RemainString == ReverseRemainString)
					{
						vector<int> pos;
						pos.push_back(root->IsWord.second);
						pos.push_back(j);
						res.push_back(pos);
					}
				}
				root = root->children[temp[k]];
			}
			if (k == temp.size())
			{
				if (root->IsWord.first && root->IsWord.second != j)
				{
					vector<int> pos;
					pos.push_back(root->IsWord.second);
					pos.push_back(j);
					res.push_back(pos);
				}
			}
			if (!root->children.empty() && k==temp.size())
			{
				TopDown(root, "", res, j);
			}
		}
		return res;
	}
	void TopDown(Trie* root,string CurrentString, vector<vector<int>>& res,int j)
	{
		if (root->children.empty())
		{
			if (root->IsWord.first && root->IsWord.second != j)
			{
				string ReverseRemainString = CurrentString;
				reverse(ReverseRemainString.begin(), ReverseRemainString.end());
				if (CurrentString == ReverseRemainString)
				{
					vector<int> pos;
					pos.push_back(root->IsWord.second);
					pos.push_back(j);
					res.push_back(pos);
				}
			}
			return;
		}
		if (!CurrentString.empty() && root->IsWord.first && root->IsWord.second != j)
		{
			string ReverseRemainString = CurrentString;
			reverse(ReverseRemainString.begin(), ReverseRemainString.end());
			if (CurrentString == ReverseRemainString)
			{
				vector<int> pos;
				pos.push_back(root->IsWord.second);
				pos.push_back(j);
				res.push_back(pos);
			}
		}
		for (pair<char, Trie*> node : root->children)
		{
			CurrentString.push_back(node.first);
			TopDown(node.second, CurrentString, res, j);
			CurrentString.pop_back();
		}
	}
};