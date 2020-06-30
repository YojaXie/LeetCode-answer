/*
����һ����ά���� board ��һ���ֵ��еĵ����б� words���ҳ�����ͬʱ�ڶ�ά������ֵ��г��ֵĵ��ʡ�
���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��
ͬһ����Ԫ���ڵ���ĸ��һ�������в������ظ�ʹ�á�

ʾ��:
����:
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

���: ["eat","oath"]
˵��:
����Լ����������붼��Сд��ĸ a-z ��ɡ�

��ʾ:
����Ҫ�Ż������㷨��ͨ�������������Ĳ��ԡ����ܷ����ֹͣ���ݣ�
�����ǰ���ʲ����������е��ʵ�ǰ׺�У����������ֹͣ���ݡ�ʲô�������ݽṹ������Ч��ִ�������Ĳ�����
ɢ�б��Ƿ���У�Ϊʲô�� ǰ׺����Σ��������ѧϰ���ʵ��һ��������ǰ׺�������Ȳ鿴������⣺ ʵ��Trie��ǰ׺������
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