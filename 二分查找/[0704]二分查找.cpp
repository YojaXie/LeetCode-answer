/*
����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� -1��

ʾ�� 1:
����: nums = [-1,0,3,5,9,12], target = 9
���: 4
����: 9 ������ nums �в����±�Ϊ 4

ʾ�� 2:
����: nums = [-1,0,3,5,9,12], target = 2
���: -1
����: 2 ������ nums ����˷��� -1

��ʾ��
����Լ��� nums �е�����Ԫ���ǲ��ظ��ġ�
n ���� [1, 10000]֮�䡣
nums ��ÿ��Ԫ�ض����� [-9999, 9999]֮�䡣
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
		for (int leftp = 0, rightp = nums.size() - 1; leftp <= rightp;)
		{
			int midp = (leftp + rightp) / 2;
			if (nums[midp] < target) leftp = midp + 1;
			else if (nums[midp] > target) rightp = midp - 1;
			else return midp;
		}
		return -1;
	}
};