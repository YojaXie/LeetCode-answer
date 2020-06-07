/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        if (nums.empty())
            return;
        int slowp = 0;
        for (int fastp = 0; fastp < nums.size(); fastp++)
        {
            if (nums[fastp] != 0)
            {
                nums[slowp] = nums[fastp];
                slowp++;
            }
        }
        for (; slowp < nums.size(); slowp++)
            nums[slowp] = 0;
    }
};