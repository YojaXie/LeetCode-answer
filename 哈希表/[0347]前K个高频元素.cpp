#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<map>

using namespace std;

class Solution 
{
public:
	vector<int> topKFrequent(vector<int>& nums, int k) 
	{
		unordered_map<int, int> KeyMapNum;
		map<int, vector<int>, greater<int>> NumMapKey;
		vector<int> res;
		int CurrentNum = 0;
		for (int key : nums)
		{
			if (KeyMapNum.count(key) == 0)
				KeyMapNum[key] = 1;
			else
				KeyMapNum[key] += 1;
		}
		for (auto KeyNum : KeyMapNum)
		{
			if (NumMapKey.count(KeyNum.second) == 0)
				NumMapKey[KeyNum.second].push_back(KeyNum.first);
			else
				NumMapKey[KeyNum.second].push_back(KeyNum.first);
		}
		for (auto NumKey : NumMapKey)
		{
			for (int Key : NumKey.second)
			{
				if (CurrentNum <= k)
				{
					CurrentNum++;
					res.push_back(Key);
				}
			}
		}
		return res;
	}
};