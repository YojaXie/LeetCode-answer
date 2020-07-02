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
	int lengthOfLongestSubstring(string s)
	{
		int MaxLen = -1;
		int CurrentLen = 0;
		unordered_map<char, int> CharMapIndex;
		for (int i = 0; i < s.size();i++)
		{
			if (CharMapIndex.count(s[i]) == 0)
			{
				CharMapIndex[s[i]] = i;
				CurrentLen += 1;
			}
			else
			{
				if (i - CharMapIndex[s[i]] > CurrentLen)
				{
					CharMapIndex[s[i]] = i;
					CurrentLen += 1;
				}
				else
				{
					MaxLen = max(CurrentLen, MaxLen);
					CurrentLen = i - CharMapIndex[s[i]];
					CharMapIndex[s[i]] = i;
				}
			}
		}
		MaxLen = max(CurrentLen, MaxLen);
		return MaxLen;
	}
};