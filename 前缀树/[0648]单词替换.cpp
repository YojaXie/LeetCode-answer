/*
在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。
例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。
如果继承词有许多可以形成它的词根，则用最短的词根替换它。
你需要输出替换之后的句子。

示例：
输入：dict(词典) = ["cat", "bat", "rat"] sentence(句子) = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"

提示：
输入只包含小写字母。
1 <= dict.length <= 1000
1 <= dict[i].length <= 100
1 <= 句中词语数 <= 1000
1 <= 句中词语长度 <= 1000
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

class Solution 
{
public:
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
		string swapSuccessor(string successor)
		{
			Trie* root = this;
			string res;
			for (char character : successor)
			{
				if (root->children.find(character) == root->children.end()) return successor;
				else
				{
					res.push_back(character);
					if (root->IsWord) return res;
					root = root->children[character];
				}
			}
			return res;
		}
	};

	string replaceWords(vector<string>& dict, string sentence) 
	{
		Trie* root = new Trie();
		for (string str : dict) root->insert(str);
		int SentenceSize = sentence.size();
		string word;
		string res;
		for (int i = 0; i < SentenceSize; i++)
		{
			if (sentence[i] == ' ')
			{
				res.append(root->swapSuccessor(word));
				res.append(' ');
				word.clear();
			}
			else 
				word.push_back(sentence[i]);
		}
		res.append(root->swapSuccessor(word));
		return res;
	}
};