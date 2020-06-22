/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		vector<int> res;
		res.push_back(-1);
		res.push_back(-1);
		int leftp = 0, rightp = nums.size() - 1;
		int temp;
		while (leftp <= rightp)
		{
			int midp = leftp + (rightp - leftp) / 2;
			if (nums[midp] > target) rightp = midp - 1;
			else if (nums[midp] < target) leftp = midp + 1;
			else
			{
				temp = midp;
				rightp = temp;
				leftp = 0;
				while (leftp < rightp)
				{
					midp = leftp + 1 + (rightp - leftp) / 2;
					if (nums[midp] == target && nums[midp - 1] != target)
					{
						res[0] = midp;
						break;
					}
					if (nums[midp] < target) leftp = midp;
					else rightp = midp - 1;
				}
				if (res[0] == -1) res[0] = rightp;

				leftp = temp;
				rightp = nums.size() - 1;
				while (leftp < rightp)
				{
					midp = leftp + (rightp - leftp) / 2;
					if (nums[midp] == target && nums[midp + 1] != target)
					{
						res[1] = midp;
						break;
					}
					if (nums[midp] > target) rightp = midp;
					else leftp = midp + 1;
				}
				if (res[1] == -1) res[1] = leftp;
				return res;
			}
		}
		return res;
	}
};