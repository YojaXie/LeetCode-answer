/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:
给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
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
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<double, int> buffer;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            auto TargetKey = buffer.find(double(target) - double(nums[i]));
            if (TargetKey != buffer.end())
            {
                res.push_back(i);
                res.push_back((*TargetKey).second);
            }
            else
                buffer[double(nums[i])] = i;
        }
        return res;
    }
};