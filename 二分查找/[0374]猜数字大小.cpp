/*
����������һ����������Ϸ�� ��Ϸ�������£�
�Ҵ� 1 �� n ѡ��һ�����֡� ����Ҫ����ѡ�����ĸ����֡�
ÿ����´��ˣ��һ��������������Ǵ��˻���С�ˡ�
�����һ��Ԥ�ȶ���õĽӿ� guess(int num)�����᷵�� 3 �����ܵĽ����-1��1 �� 0����

-1 : �ҵ����ֱȽ�С
 1 : �ҵ����ֱȽϴ�
 0 : ��ϲ����¶��ˣ�

ʾ�� :
����: n = 10, pick = 6
���: 6
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

class Solution 
{
public:
	int guessNumber(int n) 
	{
		int leftp = 0, rightp = n;
		while (leftp <= rightp)
		{
			int midp = leftp + (rightp - leftp) / 2;
			if (guess(midp) == 1) leftp = midp + 1;
			else if (guess(midp) == -1) rightp = midp - 1;
			else return midp;
		}
		return 0;
	}
};