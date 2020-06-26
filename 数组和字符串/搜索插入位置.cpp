/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0
*/

#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int mid = 0;
		int right = nums.size() - 1;
		int left = 0;
		while (right - left == 1) {
			if (target < nums[0])
				return 0;
			if (target > nums[nums.size() - 1])
				return nums.size() - 1;
			mid = (right + left) / 2;
			right = nums[mid] >= target ? mid : right;
			left = nums[mid] < target ? mid : left;

		}
		return right;

	}
};