/*
��ֵԪ����ָ��ֵ������������ֵ��Ԫ�ء�
����һ���������� nums������ nums[i] �� nums[i+1]���ҵ���ֵԪ�ز�������������
������ܰ��������ֵ������������£������κ�һ����ֵ����λ�ü��ɡ�
����Լ��� nums[-1] = nums[n] = -�ޡ�

ʾ�� 1:
����: nums = [1,2,3,1]
���: 2
����: 3 �Ƿ�ֵԪ�أ���ĺ���Ӧ�÷��������� 2��

ʾ�� 2:
����: nums = [1,2,1,3,5,6,4]
���: 1 �� 5
����: ��ĺ������Է������� 1�����ֵԪ��Ϊ 2��
	 ���߷������� 5�� ���ֵԪ��Ϊ 6��
˵��:
��ĽⷨӦ���� O(logN) ʱ�临�Ӷȵġ�
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution
{
public:
	int findPeakElement(vector<int>& nums)
	{
		int leftp = 0, rightp = nums.size() - 1;
		int midp;
		while (leftp < rightp)
		{
			midp = leftp + (rightp - leftp) / 2;
			if (nums[midp] > nums[midp + 1]) rightp = midp;
			if (nums[midp] < nums[midp + 1]) leftp = midp + 1;
		}
		return leftp;
	}
};