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
	bool isMatch(string s, string p) 
	{
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[s.size()][p.size()] = true;
		int l = s.size() + p.size() - 2;
		for ( ; l >= 0; l--)
		{
			int i = 0, j = 0;
			i = l >= s.size() ? s.size() - 1 : l;
			j = l >= s.size() ? l - s.size() + 1 : 0;
			for (; i >= 0 && j < p.size(); i--, j++)
			{
				bool first = (s[i] == p[j] || p[j] == '.') ? true : false;
				if (j + 1 < p.size() && p[j + 1] == '*')
				{
					dp[i][j] = dp[i][j + 2] || (first && dp[i + 1][j]);
					
				}
				else
				{
					dp[i][j] = dp[i + 1][j + 1] && first;
				}

			}
		}
		return dp[0][0];
	}
};