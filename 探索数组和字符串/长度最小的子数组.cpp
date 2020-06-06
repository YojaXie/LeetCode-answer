/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

示例:

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int minlen = INT_MAX;
        int sum = 0;
        bool flag = false;
        for (int i = -1, j = -1; i < int(nums.size()); )
        {
            if (sum < s)
            {
                i++;
                if (i == nums.size())
                    break;
                sum += nums[i];
            }
            if (sum >= s)
            {
                flag = true;
                minlen = min(minlen, i - j);
                j++;
                sum -= nums[j];
            }
        }
        if (!flag)
            return 0;
        return minlen;
    }
};
