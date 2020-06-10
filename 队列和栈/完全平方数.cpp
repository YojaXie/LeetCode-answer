/*
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:
输入: n = 12
输出: 3
解释: 12 = 4 + 4 + 4.

示例 2:
输入: n = 13
输出: 2
解释: 13 = 4 + 9.
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        int nummax = sqrt(n);
        vector<int> beijianshu;
        for (int i = nummax; i >= 1; i--)
            beijianshu.push_back(i * i);
        queue<int> queuenum;
        set<int> used;
        int step = 0;
        int root = n;
        used.insert(n);
        queuenum.push(root);
        while (!queuenum.empty())
        {
            step = step + 1;
            int size = queuenum.size();
            for (int i = 0; i < size; i++)
            {
                int RemainNum = queuenum.front();
                queuenum.pop();
                for (int i = 0; i <nummax; i++)
                {
                    int SaveNum = RemainNum - beijianshu[i];
                    if (SaveNum == 0)
                        return step;
                    if (SaveNum > 0 && used.count(SaveNum) == 0)
                    {
                        queuenum.push(SaveNum);
                        used.insert(SaveNum);
                    }
                }
            }
        }
        return -1;
    }
};