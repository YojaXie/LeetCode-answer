/*
在整数数组 nums 中，是否存在两个下标 i 和 j，
使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的绝对值也小于等于 ķ 。
如果存在则返回 true，不存在返回 false。

示例 1:
输入: nums = [1,2,3,1], k = 3, t = 0
输出: true

示例 2:
输入: nums = [1,0,1,1], k = 1, t = 2
输出: true

示例 3:
输入: nums = [1,5,9,1,5,9], k = 2, t = 3
输出: false
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) 
    {
        if (nums.empty()) return false;
        if (k <= 0) return false;
        set<long int> buffer;
        buffer.insert(nums[0]);
        for (int i = 1; i < nums.size(); i++)
        {
            set<long int>::iterator GreatEqualMin = buffer.lower_bound(nums[i]);
            if (GreatEqualMin != buffer.end())
            {
                if((*GreatEqualMin) - double(nums[i]) <= t) return true;
            }
            set<long int>::iterator LessEqualMax = buffer.lower_bound(double(nums[i]) - double(t));
            if (LessEqualMax != buffer.end())
            {
                if ((*LessEqualMax) <= nums[i]) return true;
            }
            buffer.insert(nums[i]);
            if (buffer.size() > k) buffer.erase(buffer.find(nums[i - k]));
        }
        return false;
    }
};