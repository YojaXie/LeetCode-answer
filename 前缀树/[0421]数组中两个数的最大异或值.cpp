/*
����һ���ǿ����飬������Ԫ��Ϊ a0, a1, a2, �� , an-1������ 0 �� ai < 2^31 ��
�ҵ� ai ��aj ������� (XOR) ������������0 �� i,  j < n ��
������O(n)��ʱ�������������

ʾ��:
����: [3, 10, 5, 25, 2, 8]
���: 28
����: ���Ľ���� 5 ^ 25 = 28.
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
		int MaxNum = -1;
		TopDown(root, root, 0, MaxNum);
		return MaxNum;
	}

	void TopDown(Trie* RootLeft, Trie* RootRight,int CurrentNum, int& MaxNum)
	{
		CurrentNum = (RootLeft->val ^ RootRight->val) + (CurrentNum << 1);
		if (RootLeft->children.empty())
		{
			MaxNum = max(MaxNum, CurrentNum);
			return;
		}
		if (RootLeft->children.size() == 1 && RootRight->children.size() == 1)
			TopDown((*RootLeft->children.begin()).second, (*RootRight->children.begin()).second, CurrentNum, MaxNum);
		else if (RootLeft->children.size() == 1 && RootRight->children.size() == 2)
		{
			int LeftChildrenVakl = (*RootLeft->children.begin()).second->val;
			TopDown((*RootLeft->children.begin()).second, RootRight->children[1 - LeftChildrenVakl], CurrentNum, MaxNum);
		}
		else if (RootLeft->children.size() == 2 && RootRight->children.size() == 1)
		{
			int RightChildrenVakl = (*RootRight->children.begin()).second->val;
			TopDown(RootLeft->children[1 - RightChildrenVakl], (*RootRight->children.begin()).second, CurrentNum, MaxNum);
		}
		else
		{
			for (pair<int, Trie*> node : RootLeft->children)
			{
				TopDown(node.second, RootRight->children[1 - node.first], CurrentNum, MaxNum);
			}
		}
	}
};