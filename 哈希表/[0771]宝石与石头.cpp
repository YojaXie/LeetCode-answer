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
	int numJewelsInStones(string J, string S) 
	{
		unordered_set<char>JSet;
		for (char c : J) JSet.insert(c);
		int res = 0;
		for (char c : S)
		{
			if (JSet.count(c) > 0)
				res += 1;
		}
		return res;
	}
};