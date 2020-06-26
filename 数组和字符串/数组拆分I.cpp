/*
��������Ϊ 2n ������, ��������ǽ���Щ���ֳ� n ��, ���� (a1, b1), (a2, b2), ..., (an, bn) ��ʹ�ô�1 �� n �� min(ai, bi) �ܺ����

ʾ�� 1:

����: [1,4,3,2]

���: 4
����: n ���� 2, ����ܺ�Ϊ 4 = min(1, 2) + min(3, 4).
��ʾ:

n ��������,��Χ�� [1, 10000].
�����е�Ԫ�ط�Χ�� [-10000, 10000].
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
	int arrayPairSum(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());
		vector<int>::iterator leftp = nums.begin();
		vector<int>::iterator rightp = nums.begin() + 1;
		int sum = 0;
		for (; rightp < nums.end() ; rightp+=2, leftp+=2)
		{
			sum += min(*leftp, *rightp);
		}
		return sum;
	}
};

