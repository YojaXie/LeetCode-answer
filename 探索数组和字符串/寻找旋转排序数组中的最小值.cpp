/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

请找出其中最小的元素。

你可以假设数组中不存在重复元素。

示例 1:

输入: [3,4,5,1,2]
输出: 1
示例 2:

输入: [4,5,6,7,0,1,2]
输出: 0
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        if (nums[0] <= nums[nums.size() - 1])
            return nums[0];
        int lefti = 0;
        int temp = nums[0];
        for (int righti = nums.size() - 1; lefti < righti;)
        {
            if (nums[(righti + lefti) / 2] >= temp)
                lefti = (righti + lefti) / 2 + 1;
            if (nums[(righti + lefti) / 2] < temp)
                righti = (righti + lefti) / 2;
        }
        return nums[lefti];
    }
};