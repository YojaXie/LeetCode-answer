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
	bool canPartition(vector<int>& nums) 
	{
		if (nums.empty()) return true;
		int TotalSum = 0;
		for (int num : nums)
			TotalSum += num;
		if (TotalSum % 2 == 1) return false;
		vector<bool> dp(TotalSum / 2 + 1, false);
		dp[0] = true;
		for (int j = 0; j < nums.size(); j++)
		{
			for (int i = dp.size() - 1; i < dp.size(); i--)
			{
				if (nums[j] > i) continue;
				dp[i] = dp[i - nums[j]];
			}
		}
		return dp.back();
	}
};