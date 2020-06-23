/*
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
说明：不要使用任何内置的库函数，如  sqrt。

示例 1：
输入：16
输出：True

示例 2：
输入：14
输出：False
*/

#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

class Solution 
{
public:
	bool isPerfectSquare(int num) 
	{
		int leftp = 1, rightp = num;
		long int midp = 0;
		while (leftp <= rightp)
		{
			midp = leftp + (rightp - leftp) / 2;
			if (midp * midp > num) rightp = midp - 1;
			else if (midp * midp < num) leftp = midp + 1;
			else return true;
		}
		return false;
	}
};