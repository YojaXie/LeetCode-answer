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

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int profit = 0;
		vector<int> dp(prices.size(), 0);
		dp[0] = prices[0];
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > dp[i - 1]) {
				profit = max(profit, prices[i] - dp[i - 1]);
				dp[i] = dp[i - 1];
			}
			else
				dp[i] = prices[i];
		}
		return profit;
	}
};