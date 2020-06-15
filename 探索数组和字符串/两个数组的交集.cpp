/*
给定两个数组，编写一个函数来计算它们的交集。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
 
说明：
输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		int fastP = 0;
		int slowP = 0;
		vector<int> res;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		while (fastP < nums1.size() && slowP < nums2.size())
		{
			if (nums1[fastP] < nums2[slowP]) fastP++;
			else if (nums1[fastP] > nums2[slowP]) slowP++;
			else
			{
				if (!res.empty())
				{
					if (res.back() == nums1[fastP])
					{
						fastP++;
						slowP++;
						continue;
					}
				}
				res.push_back(nums1[fastP]);
				fastP++;
				slowP++;
			}
		}
		return res;
	}
};