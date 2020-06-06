/*
给定一个二进制数组， 计算其中最大连续1的个数。

示例 1:

输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：

输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxnum = 0;
        for (int i = 0, j = -1; i <= nums.size(); i++)
        {
            if (i == nums.size())
            {
                maxnum = max(i - j - 1, maxnum);
                j = i;
                break;
            }
            if (nums[i] == 0)
            {
                maxnum = max(i - j - 1, maxnum);
                j = i;
            }
        }
        return maxnum;
    }
};