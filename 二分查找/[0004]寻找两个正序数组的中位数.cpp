/*
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。

示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0

示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int LeftNums1 = 0, RightNums1 = nums1.size();
		int LeftNums2 = 0, RightNums2 = nums2.size();
		int NumSum = nums1.size() + nums2.size();
		if (NumSum % 2 == 1)
		{
			while (LeftNums1 < RightNums1)
			{
				int MidNums1 = LeftNums1 + (RightNums1 - LeftNums1) / 2;
				int MidNums2 = TargetLeftNumber1(nums2, nums1[MidNums1]);
				if (MidNums1 + MidNums2 < (NumSum - 1) / 2) LeftNums1 = MidNums1 + 1;
				else if (MidNums1 + MidNums2 > (NumSum - 1) / 2) RightNums1 = MidNums1;
				else return nums1[MidNums1];
			}
			while (LeftNums2 < RightNums2)
			{
				int MidNums2 = LeftNums2 + (RightNums2 - LeftNums2) / 2;
				int MidNums1 = TargetLeftNumber2(nums1, nums2[MidNums2]);
				if (MidNums1 + MidNums2 < (NumSum - 1) / 2) LeftNums2 = MidNums2 + 1;
				else if (MidNums1 + MidNums2 > (NumSum - 1) / 2) RightNums2 = MidNums2;
				else return nums2[MidNums2];
			}
		}
		else
		{
			while (LeftNums1 < RightNums1)
			{
				int MidNums1 = LeftNums1 + (RightNums1 - LeftNums1) / 2;
				int MidNums2 = TargetLeftNumber1(nums2, nums1[MidNums1]);
				if (MidNums1 + MidNums2 < (NumSum - 2) / 2) LeftNums1 = MidNums1 + 1;
				else if (MidNums1 + MidNums2 > (NumSum - 2) / 2) RightNums1 = MidNums1;
				else
				{
					if (MidNums2 == nums2.size() || nums2.size() == 0) return double(nums1[MidNums1] + nums1[MidNums1 + 1]) / 2;
					if (MidNums1 == nums1.size() - 1) return double(nums1[MidNums1] + nums2[MidNums2]) / 2;
					if (nums1[MidNums1 + 1] <= nums2[MidNums2]) return double(nums1[MidNums1] + nums1[MidNums1 + 1]) / 2;
					else return double(nums1[MidNums1] + nums2[MidNums2]) / 2;
				}
			}
			while (LeftNums2 < RightNums2)
			{
				int MidNums2 = LeftNums2 + (RightNums2 - LeftNums2) / 2;
				int MidNums1 = TargetLeftNumber2(nums1, nums2[MidNums2]);
				if (MidNums1 + MidNums2 < (NumSum - 2) / 2) LeftNums2 = MidNums2 + 1;
				else if (MidNums1 + MidNums2 > (NumSum - 2) / 2) RightNums2 = MidNums2;
				else
				{
					if (MidNums1 == nums1.size() || nums1.size() == 0) return double(nums2[MidNums2] + nums2[MidNums2 + 1]) / 2;
					if (MidNums2 == nums2.size() - 1) return double(nums1[MidNums1] + nums2[MidNums2]) / 2;
					if (nums2[MidNums2 + 1] <= nums1[MidNums1]) return double(nums2[MidNums2] + nums2[MidNums2 + 1]) / 2;
					else return double(nums1[MidNums1] + nums2[MidNums2]) / 2;
				}
			}
		}
		return 0.0;
	}
	int TargetLeftNumber1(vector<int>& nums, int target)
	{
		int leftp = 0, rightp = nums.size();
		while (leftp < rightp)
		{
			int midp = leftp + (rightp - leftp) / 2;
			if (nums[midp] > target) rightp = midp;
			else if (nums[midp] < target) leftp = midp + 1;
			else return midp;
		}
		return rightp;
	}

	int TargetLeftNumber2(vector<int>& nums, int target)
	{
		int leftp = 0, rightp = nums.size();
		while (leftp < rightp)
		{
			int midp = leftp + (rightp - leftp) / 2;
			if (nums[midp] > target) rightp = midp;
			else if (nums[midp] < target) leftp = midp + 1;
			else return midp + 1;
		}
		return rightp;
	}
};