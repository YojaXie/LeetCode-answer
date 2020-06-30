/*
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母在一个单词中不允许被重复使用。

示例:
输入:
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

输出: ["eat","oath"]
说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:
你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？
散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
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
		bool IsWord;
		unordered_map<char, Trie*> children;
	public:
		Trie()
		{
			IsWord = false;
		}
		void insert(string word)
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
			root->IsWord = true;
		}
	};

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
	{
		vector<string> res;
		if (board.empty()) return res;
		if (words.empty()) return res;
		Trie* root = new Trie();
		for (string str : words) root->insert(str);
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				set<pair<int, int>> buffer;
				TopDown(board, i, j, root, "", res, buffer);
			}
		}
		return res;

	}
	void TopDown(vector<vector<char>>& board, int r, int c, Trie* root, string CurrentString, vector<string>& res, set<pair<int, int>>& buffer)
	{

		if (root->children.find(board[r][c]) == root->children.end()) return;
		buffer.insert({ r,c });
		CurrentString.push_back(board[r][c]);
		if (root->children[board[r][c]]->IsWord)
		{
			res.push_back(CurrentString);
			root->children[board[r][c]]->IsWord = false;
		}
		if (r - 1 >= 0 && buffer.find({ r - 1,c }) == buffer.end())
			TopDown(board, r - 1, c, root->children[board[r][c]], CurrentString, res, buffer);
		if (r + 1 < board.size() && buffer.find({ r + 1,c }) == buffer.end())
			TopDown(board, r + 1, c, root->children[board[r][c]], CurrentString, res, buffer);
		if (c - 1 >= 0 && buffer.find({ r,c - 1 }) == buffer.end())
			TopDown(board, r, c - 1, root->children[board[r][c]], CurrentString, res, buffer);
		if (c + 1 < board[0].size() && buffer.find({ r,c + 1 }) == buffer.end())
			TopDown(board, r, c + 1, root->children[board[r][c]], CurrentString, res, buffer);
		buffer.erase({ r,c });
	}
};