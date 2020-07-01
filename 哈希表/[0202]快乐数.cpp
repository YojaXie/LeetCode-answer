/*
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。
如果 n 是快乐数就返回 True ；不是，则返回 False 。

示例：
输入：19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;
// MAX_INT = 2147483647
class Solution 
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> used;
        while (used.count(n) == 0)
        {
            used.insert(n);
            int sum = 0;
            for (int i = 9; i >= 0; i--)
            {
                int NumIth = (n / int(pow(10, i))) % 10;
                if (NumIth != 0)
                {
                    while (i >= 0)
                    {
                        NumIth = (n / int(pow(10, i))) % 10;
                        sum += NumIth * NumIth;
                        i--;
                    }
                }
            }
            n = sum;
            if (sum == 1) return true;
        }
        return false;
    }
};