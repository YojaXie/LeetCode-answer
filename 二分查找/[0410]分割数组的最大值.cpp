/*
����һ���Ǹ����������һ������ m������Ҫ���������ֳ� m ���ǿյ����������顣���һ���㷨ʹ���� m ����������Ժ͵����ֵ��С��

ע��:
���鳤�� n ������������:
1 �� n �� 1000
1 �� m �� min(50, n)

ʾ��:
����:
nums = [7,2,5,10,8]
m = 2
���:
18

����:
һ�������ַ�����nums�ָ�Ϊ2�������顣
������õķ�ʽ�ǽ����Ϊ[7,2,5] �� [10,8]��
��Ϊ��ʱ��������������Եĺ͵����ֵΪ18���������������С��
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
	int splitArray(vector<int>& nums, int m) 
	{
		int leftp = *max_element(nums.begin(), nums.end());
		if (nums.size() == m) return leftp;
		int rightp = 0;
		for (int i = 0; i < nums.size(); i++) rightp += nums[i];
		while (leftp < rightp)
		{
			int midp = leftp + (rightp - leftp) / 2;
			if (targetSumIntervalNumber(nums, midp) > m) leftp = midp + 1;
			else rightp = midp;
		}
		return rightp;
	}
	int targetSumIntervalNumber(vector<int>& nums, int target)
	{
		int res = 0;
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			if (sum > target || i==nums.size()-1)
			{
				sum = nums[i];
				res++;
			}
		}
		return res;
	}
};