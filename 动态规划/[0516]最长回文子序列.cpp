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
	int longestPalindromeSubseq(string s) 
	{
		if (s.empty()) return 0;
		vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
		for (int i = 0; i < s.size(); i++)
			dp[i][i] = 1;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			for (int j = i + 1; j < s.size(); j++)
			{
				if (s[i] == s[j])
					dp[i][j] = 2 + dp[i + 1][j - 1];
				else
				{
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][s.size()-1];
	}
};