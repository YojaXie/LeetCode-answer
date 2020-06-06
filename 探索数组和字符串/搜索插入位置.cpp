/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

����Լ������������ظ�Ԫ�ء�

ʾ�� 1:

����: [1,3,5,6], 5
���: 2
ʾ�� 2:

����: [1,3,5,6], 2
���: 1
ʾ�� 3:

����: [1,3,5,6], 7
���: 4
ʾ�� 4:

����: [1,3,5,6], 0
���: 0
*/

#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int mid = 0;
		int right = nums.size() - 1;
		int left = 0;
		while (right - left == 1) {
			if (target < nums[0])
				return 0;
			if (target > nums[nums.size() - 1])
				return nums.size() - 1;
			mid = (right + left) / 2;
			right = nums[mid] >= target ? mid : right;
			left = nums[mid] < target ? mid : left;

		}
		return right;

	}
};