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
	int coinChange(vector<int>& coins, int amount) 
	{
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (int i = 0; i < amount + 1; i++)
		{
			for (int coin : coins)
			{
				if (i - coin < 0) continue;
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
		return dp[amount] == amount + 1 ? -1 : dp[amount];
	}
};