/*
����һ������ļ��ϣ���ϲ������ص������䡣

ʾ�� 1:

����: [[1,3],[2,6],[8,10],[15,18]]
���: [[1,6],[8,10],[15,18]]
����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
ʾ�� 2:

����: [[1,4],[4,5]]
���: [[1,5]]
����: ���� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣

˼·��������������ֵ�������ж�������ֵ�Ĵ�С��ϵ��
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
