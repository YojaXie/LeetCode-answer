/*
ʵ�� int sqrt(int x) ������
���㲢���� x ��ƽ���������� x �ǷǸ�������
���ڷ������������������ֻ���������Ĳ��֣�С�����ֽ�����ȥ��

ʾ�� 1:
����: 4
���: 2

ʾ�� 2:
����: 8
���: 2
˵��: 8 ��ƽ������ 2.82842...,
���ڷ���������������С�����ֽ�����ȥ��
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution 
{
public:
	int mySqrt(int x) 
	{
		int leftp = 0, rightp = x;
		while (leftp <= rightp)
		{
			long int midp = leftp + (rightp - leftp) / 2;
			if ((midp + 1) * (midp + 1) > x && midp * midp <= x) return midp;
			else if ((midp + 1) * (midp + 1) < x) leftp = midp + 1;
			else if (midp * midp > x) rightp = midp - 1;
			else return midp+1;
		}
		return 0;
	}
};