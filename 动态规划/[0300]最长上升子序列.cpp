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

//动态规划
class Solution1 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// 贪心+二分
class Solution2
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.empty()) return 0;
        vector<int> MinValOfLen(1, nums[0]);
        for (int num : nums)
        {
            if (num > MinValOfLen.back())
            {
                MinValOfLen.push_back(num);
            }
            else
            {
                int index = binarySearch(MinValOfLen, num);
                MinValOfLen[index] = num;
            }
        }
        return MinValOfLen.size();
    }
    int binarySearch(vector<int>& MinValOfLen, int target)
    {
        int low = 0, high = MinValOfLen.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (MinValOfLen[mid] < target)
                low = mid + 1;
            else
            {
                high = mid;
            }
        }
        return low;
    }
};