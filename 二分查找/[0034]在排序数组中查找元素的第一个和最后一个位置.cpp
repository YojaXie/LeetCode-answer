/*
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�
����㷨ʱ�临�Ӷȱ����� O(log n) ����
��������в�����Ŀ��ֵ������ [-1, -1]��

ʾ�� 1:
����: nums = [5,7,7,8,8,10], target = 8
���: [3,4]

ʾ�� 2:
����: nums = [5,7,7,8,8,10], target = 6
���: [-1,-1]
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