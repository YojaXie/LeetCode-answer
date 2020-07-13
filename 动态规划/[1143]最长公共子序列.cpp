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
	int longestCommonSubsequence(string text1, string text2) 
	{
		vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
		for (int i = 0; i < text1.size() + 1; i++)
		{
			for (int j = 0; j < text2.size() + 1; j++)
			{
				if (text1[i] == text2[j])
					dp[i + 1][j + 1] = 1 + dp[i][j];
				else
				{
					dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				}
			}
		}
		return dp[text1.size()][text2.size()];
	}
};