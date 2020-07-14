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
    int maxCoins(vector<int>& nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], nums[i] * nums[j] * nums[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][nums.size() - 1];
    }
};