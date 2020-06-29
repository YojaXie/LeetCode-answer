/*
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true

说明:
你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
*/

#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Trie 
{
private:
	bool IsWord;
	unordered_map<char, Trie*> children;
public:
	/** Initialize your data structure here. */
	Trie()
	{
		IsWord = false;
	}
	/** Inserts a word into the trie. */
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
	/** Returns if the word is in the trie. */
	bool search(string word)
	{
		Trie* root = this;
		for (char character : word)
		{
			if (root->children.find(character) == root->children.end()) return false;
			else root = root->children[character];
		}
		return root->IsWord;
	}
	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix)
	{
		Trie* root = this;
		for (char character : prefix)
		{
			if (root->children.find(character) == root->children.end()) return false;
			else root = root->children[character];
		}
		return true;
	}
};