/*
���ǲ�Ʒ����Ŀǰ���ڴ���һ���Ŷӿ����µĲ�Ʒ�����ҵ��ǣ���Ĳ�Ʒ�����°汾û��ͨ��������⡣
����ÿ���汾���ǻ���֮ǰ�İ汾�����ģ����Դ���İ汾֮������а汾���Ǵ�ġ�
�������� n ���汾 [1, 2, ..., n]�������ҳ�����֮�����а汾����ĵ�һ������İ汾��
�����ͨ������ bool isBadVersion(version) �ӿ����жϰ汾�� version �Ƿ��ڵ�Ԫ�����г���
ʵ��һ�����������ҵ�һ������İ汾����Ӧ�þ������ٶԵ��� API �Ĵ�����

ʾ��:
���� n = 5������ version = 4 �ǵ�һ������İ汾��

���� isBadVersion(3) -> false
���� isBadVersion(5) -> true
���� isBadVersion(4) -> true

���ԣ�4 �ǵ�һ������İ汾��
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution 
{
public:
	int firstBadVersion(int n) 
	{
		int leftp = 0, rightp = n;
		while (leftp < rightp)
		{
			int midp = leftp + 1 + (rightp - leftp) / 2;
			if (!isBadVersion(midp - 1) && isBadVersion(midp)) return midp;
			else if (isBadVersion(midp - 1)) rightp=midp-1;
			else leftp = midp;
		}
		return -1;
	}
};