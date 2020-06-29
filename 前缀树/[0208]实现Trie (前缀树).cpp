/*
ʵ��һ�� Trie (ǰ׺��)������ insert, search, �� startsWith ������������

ʾ��:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // ���� true
trie.search("app");     // ���� false
trie.startsWith("app"); // ���� true
trie.insert("app");
trie.search("app");     // ���� true

˵��:
����Լ������е����붼����Сд��ĸ a-z ���ɵġ�
��֤���������Ϊ�ǿ��ַ�����
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