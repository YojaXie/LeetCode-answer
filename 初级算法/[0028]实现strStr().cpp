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
	int strStr(string haystack, string needle)
	{
		if (needle.empty()) return 0;
		vector<int> next(needle.size());
		int i = 2, j = 0;
		while (i < needle.size())
		{
			if (needle[i - 1] == needle[j])
			{
				if (needle[i - 1] != needle[i])
					next[i] = j + 1;
				else
					next[i] = next[j];
				i++;
				j++;
			}
			else
			{
				if (j == 0)
					i++;
				j = next[j];
			}
		}
		int next_p = 0;
		i = 0;
		while (next_p < needle.size() && i < haystack.size())
		{
			if (needle[next_p] == haystack[i])
			{
				next_p++;
				i++;
				if (next_p == needle.size()) return i - next_p;
			}
			else
			{
				if (next_p == 0)
				{
					i++;
				}
				else
				{
					next_p = next[next_p];
				}
			}
		}
		return -1;
	}
};