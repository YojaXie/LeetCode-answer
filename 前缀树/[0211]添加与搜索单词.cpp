/*
设计一个支持以下两种操作的数据结构：
void addWord(word)
bool search(word)
search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。

示例:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

说明:
你可以假设所有单词都是由小写字母 a-z 组成的。
*/

#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<queue>

using namespace std;

class WordDictionary 
{
private:
	bool IsWord;
	unordered_map<char, WordDictionary*> children;
public:
	/** Initialize your data structure here. */
	WordDictionary() 
	{
		IsWord = false;
	}

	/** Adds a word into the data structure. */
	void addWord(string word) 
	{
		WordDictionary* root = this;
		for (char character : word)
		{
			if (root->children.find(character) == root->children.end())
			{
				WordDictionary* NewTrie = new WordDictionary();
				root->children.insert({ character,NewTrie });
			}
			root = root->children[character];
		}
		root->IsWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) 
	{
		if (word.empty()) return false;
		WordDictionary* root = this;
		bool res = false;
		TopDown(root, word, 0, res);
		return res;
	}
	void TopDown(WordDictionary* root, string word, int FirstIndex, bool& res)
	{
		if (FirstIndex >= word.size())
		{
			if (root->IsWord) res = true;
			return;
		}
		char FirstChar = word[FirstIndex];
		if (FirstChar == '.')
		{
			for (pair<char, WordDictionary*> ChildrenNode : root->children)
				TopDown(ChildrenNode.second, word, FirstIndex + 1, res);
		}
		else
		{
			if (root->children.find(FirstChar) == root->children.end()) return;
			else TopDown(root->children[FirstChar], word, FirstIndex + 1, res);
		}
	}
};