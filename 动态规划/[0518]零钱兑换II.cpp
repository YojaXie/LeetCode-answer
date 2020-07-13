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
	int change(int amount, vector<int>& coins)
	{

		vector<int> dp(amount + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < coins.size(); i++)
		{
			int coin = coins[i];
			for (int j = 1; j <= amount; j++)
			{
				if (coin <= j)
				{
					dp[j] = dp[j] + dp[j - coin];
				}
			}
		}
		return dp[amount];
	}
};