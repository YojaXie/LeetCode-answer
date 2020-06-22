/*
����һ������õ����飬�������� k �� x�����������ҵ���� x������֮����С���� k ������
���صĽ������Ҫ�ǰ������źõġ�������������� x �Ĳ�ֵһ��������ѡ����ֵ��С���Ǹ�����

ʾ�� 1:
����: [1,2,3,4,5], k=4, x=3
���: [1,2,3,4]

ʾ�� 2:
����: [1,2,3,4,5], k=4, x=-1
���: [1,2,3,4]

˵��:
k ��ֵΪ������������С�ڸ�����������ĳ��ȡ�
���鲻Ϊ�գ��ҳ��Ȳ����� 104
�������ÿ��Ԫ���� x �ľ���ֵ������ 104

����(2017/9/19):
������� arr �Ѿ����ı�Ϊһ���������飨�����������б��� �����¼��ش��붨���Ի�ȡ���¸��ġ�
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) 
	{
		int leftp = 0, rightp = arr.size() - 1;
		int midp;
		while (leftp <= rightp)
		{
			midp = leftp + (rightp - leftp) / 2;
			if (arr[midp] < x) leftp = midp + 1;
			else if (arr[midp] > x) rightp = midp - 1;
			else break;
		}
		leftp = midp - k / 2;
		rightp = midp + k - k/2 - 1;

		while (leftp < rightp)
		{
			if (leftp< 0)
			{
				rightp = rightp - leftp;
				leftp = 0;
			}
			if (rightp > arr.size()-1)
			{
				leftp = leftp - (rightp - arr.size() + 1);
				rightp = arr.size() - 1;
			}
			if (arr[midp] - arr[leftp] > arr[rightp] - arr[midp])
			{
				leftp++;
				rightp++;
			}
			else if (arr[midp] - arr[leftp] < arr[rightp] - arr[midp])
			{
				leftp--;
				rightp--;
			}
		}
	}
};


class Solution
{
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x)
	{
		int leftp = 0, rightp = arr.size() - 1;
		int midp = 0;
		while (leftp + 1 < rightp)
		{
			midp = leftp + (rightp - leftp) / 2;
			if (arr[midp] < x) leftp = midp;
			else if (arr[midp] > x) rightp = midp;
			else break;
		}
		if (leftp + 1 == rightp)
		{
			if (abs(arr[leftp] - x) - abs(arr[rightp] - x) <= 0) midp = leftp;
			else midp = rightp;
		}
		leftp = midp;
		rightp = midp;
		while (rightp - leftp + 1 < k && leftp != 0 && rightp != arr.size() - 1)
		{
			if (leftp > 0) leftp = leftp - 1;
			if (rightp < arr.size() - 1) rightp = rightp + 1;
			if (x - arr[leftp] > arr[rightp] - x) leftp = leftp + 1;
			else  rightp = rightp - 1;
		}
		if (rightp - leftp + 1 < k && rightp == arr.size() - 1) leftp = rightp + 1 - k;
		if (rightp - leftp + 1 < k && leftp == 0) rightp = leftp - 1 + k;
		vector<int> res(arr.begin() + leftp, arr.begin() + rightp + 1);
		return res;
	}
};