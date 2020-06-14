/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例：
给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() <= 2) return res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0) if (nums[i] == nums[i - 1]) continue;
            for (int j = i + 1, k = nums.size()-1; j < k;)
            {
                if (k != nums.size() - 1) if (nums[k] == nums[k + 1])
                {
                    k--;
                    continue;
                }
                if (j != i + 1) if (nums[j] == nums[j - 1])
                {
                    j++;
                    continue;
                }
                if (nums[k] > -nums[i] - nums[j]) k--;
                else if (nums[k] < -nums[i] - nums[j]) j++;
                else
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    res.push_back(temp);
                    k--; j++;
                }
            }
        }
        return res;
    }
};
