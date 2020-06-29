/*
��Ӣ���У�������һ������ �ʸ�(root)�ĸ�������Ը�������һЩ�������һ���ϳ��ĵ��ʡ������ǳ������Ϊ �̳д�(successor)��
���磬�ʸ�an�������ŵ��� other(����)�������γ��µĵ��� another(��һ��)��
���ڣ�����һ�������ʸ���ɵĴʵ��һ�����ӡ�����Ҫ�������е����м̳д��ôʸ��滻����
����̳д����������γ����Ĵʸ���������̵Ĵʸ��滻����
����Ҫ����滻֮��ľ��ӡ�

ʾ����
���룺dict(�ʵ�) = ["cat", "bat", "rat"] sentence(����) = "the cattle was rattled by the battery"
�����"the cat was rat by the bat"

��ʾ��
����ֻ����Сд��ĸ��
1 <= dict.length <= 1000
1 <= dict[i].length <= 100
1 <= ���д����� <= 1000
1 <= ���д��ﳤ�� <= 1000
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