/*
我们正在玩一个猜数字游戏。 游戏规则如下：
我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
每次你猜错了，我会告诉你这个数字是大了还是小了。
你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：

-1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！

示例 :
输入: n = 10, pick = 6
输出: 6
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