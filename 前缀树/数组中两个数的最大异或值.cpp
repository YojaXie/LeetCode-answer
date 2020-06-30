/*
给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 2^31 。
找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。
你能在O(n)的时间解决这个问题吗？

示例:
输入: [3, 10, 5, 25, 2, 8]
输出: 28
解释: 最大的结果是 5 ^ 25 = 28.
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution 
{
public:
	class Trie
	{
	public:
		unordered_map<int, Trie*> children;
		int val;
	public:
		Trie()
		{
			val = 0;
		}

		/** Inserts a word into the trie. */
		void insert(vector<int>& buffer)
		{
			Trie* root = this;
			for (int num : buffer)
			{
				if (root->children.find(num) == root->children.end())
				{
					Trie* NewTrie = new Trie();
					root->children.insert({ num,NewTrie });
				}
				root = root->children[num];
				root->val = num;
			}
		}
	};

	int findMaximumXOR(vector<int>& nums) 
	{
		vector<int> buffer(32);
		Trie* root = new Trie();
		for (int Num : nums)
		{
			for (int i = 0; i < 32; i++)
			{
				int temp = Num;
				temp = temp >> (31-i);
				buffer[i] = temp & 1;
			}
			root->insert(buffer);
		}


	}

	void TopDown(Trie* RootLeft, Trie* RootRight,int CurrentNum, int step, int& MaxNum)
	{
		if (RootLeft->children.empty())
		{
			CurrentNum += (RootLeft->val ^ RootLeft->val)
		}
	}
};