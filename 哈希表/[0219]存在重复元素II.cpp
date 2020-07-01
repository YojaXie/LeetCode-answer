/*
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，
使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。

示例 1:
输入: nums = [1,2,3,1], k = 3
输出: true

示例 2:
输入: nums = [1,0,1,1], k = 1
输出: true

示例 3:
输入: nums = [1,2,3,1,2,3], k = 2
输出: false
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;

class Solution 
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> NumMapIndex;
        for (int i = 0; i < nums.size(); i++)
        {
            if (NumMapIndex.count(nums[i]) > 0)
            {
                if (i - NumMapIndex[nums[i]] <= k)
                    return true;
                else
                    NumMapIndex[nums[i]] = i;
            }
            else
                NumMapIndex[nums[i]] = i;
        }
        return false;
    }
};