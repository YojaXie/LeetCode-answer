/*
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

思路：先排序左区间值排序，再判断右区间值的大小关系。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		if (intervals.empty())
			return intervals;
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> ans;
		for (int i = 0; i < intervals.size()-1; i++)
		{
			if (intervals[i][1] >= intervals[i + 1][0])
			{
				intervals[i + 1][1] = max(intervals[i][1], intervals[i + 1][1]);
				intervals[i + 1][0] = intervals[i][0];
			}
			else
				ans.push_back(intervals[i]);

		}
		ans.push_back(intervals[intervals.size() - 1]);

		return ans;
	}
};
