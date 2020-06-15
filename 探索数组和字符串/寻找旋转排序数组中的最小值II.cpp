/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
请找出其中最小的元素。
注意数组中可能存在重复的元素。

示例 1：
输入: [1,3,5]
输出: 1

示例 2：
输入: [2,2,2,0,1]
输出: 0

说明：
这道题是 寻找旋转排序数组中的最小值 的延伸题目。
允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
	int findMin(vector<int>& nums)
	{
		if (nums[0] < nums[nums.size() - 1])
			return nums[0];
		int lefti = 0;
		int temp = nums[0];
		int res = INT_MAX;
		int righti = nums.size() - 1;
		binary(nums, lefti, righti, temp, res);
		return res;
	}
	void binary(vector<int>& nums, int lefti, int righti, int temp, int& res)
	{
		if (lefti >= righti)
		{
			res = min(nums[lefti], res);
			return;
		}
		if (nums[(righti + lefti) / 2] > temp)
		{
			lefti = (righti + lefti) / 2 + 1;
			binary(nums, lefti, righti, temp, res);
		}
		else if (nums[(righti + lefti) / 2] < temp)
		{
			righti = (righti + lefti) / 2;
			binary(nums, lefti, righti, temp, res);
		}
		else
		{
			binary(nums, (righti + lefti) / 2 + 1, righti, temp, res);
			binary(nums, lefti, (righti + lefti) / 2, temp, res);
		}
	}
};