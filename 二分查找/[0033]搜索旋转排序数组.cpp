/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��
( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��
����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��
����Լ��������в������ظ���Ԫ�ء�
����㷨ʱ�临�Ӷȱ����� O(log n) ����

ʾ�� 1:
����: nums = [4,5,6,7,0,1,2], target = 0
���: 4

ʾ�� 2:
����: nums = [4,5,6,7,0,1,2], target = 3
���: -1
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
	int search(vector<int>& nums, int target) 
	{
		if (nums.empty()) return -1;
		if (target >= nums[0])
		{
			int leftp = 0, rightp = nums.size() - 1;
			while (leftp <= rightp)
			{
				int midp = leftp + (rightp - leftp) / 2;
				if (nums[midp] > target) rightp = midp - 1;
				else if (nums[midp] < target && nums[midp] < nums[0]) rightp = midp - 1;
				else if (nums[midp] < target && nums[midp] >= nums[0]) leftp = midp + 1;
				else return midp;
			}
		}
		else
		{
			int leftp = 0, rightp = nums.size() - 1;
			while (leftp <= rightp)
			{
				int midp = leftp + (rightp - leftp) / 2;
				if (nums[midp] > target && nums[midp] < nums[0]) rightp = midp - 1;
				else if (nums[midp] > target && nums[midp] >= nums[0]) leftp = midp + 1;
				else if (nums[midp] < target) leftp = midp + 1;
				else return midp;
			}
		}
		return -1;
	}
};