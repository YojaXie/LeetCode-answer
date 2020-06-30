/*
����һ��Ψһ�ĵ��ʣ� �ҳ����в�ͬ ��������(i, j)��ʹ���б��е��������ʣ� words[i] + words[j] ����ƴ�ӳɻ��Ĵ���

ʾ�� 1:
����: ["abcd","dcba","lls","s","sssll"]
���: [[0,1],[1,0],[3,2],[2,4]]
����: ��ƴ�ӳɵĻ��Ĵ�Ϊ ["dcbaabcd","abcddcba","slls","llssssll"]

ʾ�� 2:
����: ["bat","tab","cat"]
���: [[0,1],[1,0]]
����: ��ƴ�ӳɵĻ��Ĵ�Ϊ ["battab","tabbat"]
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
		Trie* root = new Trie();
		for (int i = 0; i < words.size(); i++) root->insert(words[i], i);

		for (int j = 0; j < words.size(); j++)
		{
			string temp = words[j];
			reverse(temp.begin(), temp.end());
			int k = 0;
			for (; k < temp.size(); k++)
			{
				if (root->children.find(temp[k]) == root->children.end())
				{
					if (root->IsWord.first && root->IsWord.second != j)
					{
						string RemainString;
						while (k < temp.size())
						{
							RemainString.push_back(temp[k]);
							k++;
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
				root = root->children[temp[k]];
				if (root->IsWord.first && root->IsWord.second !=j)
				{
					string RemainString;
					k = k + 1;
					while (k  < temp.size())
					{
						RemainString.push_back(temp[k]);
						k++;
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
		if (!CurrentString.empty() && root->IsWord.first)
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
		if (root->children.empty())
		{
			if (root->IsWord.first)
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
		for (pair<char, Trie*> node : root->children)
		{
			CurrentString.push_back(node.first);
			TopDown(node.second, CurrentString, res, j);
		}
	}
};