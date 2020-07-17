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
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		vector<int> dp(nums.size() + 1, 0);
		dp[1] = nums[0];
		dp[2] = nums[1];
		for (int i = 3; i <= nums.size(); i++) {
			dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i - 1];
		}
		return *max_element(dp.begin(), dp.end());
	}
};