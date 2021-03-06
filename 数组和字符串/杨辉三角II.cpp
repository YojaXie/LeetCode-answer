/*
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]
进阶：

你可以优化你的算法到 O(k) 空间复杂度吗？
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> res(rowIndex+1,0);
        vector<int> temp;
        for (int i = 0; i <= rowIndex; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 || j == i)
                    res[j] = 1;
                else
                    res[j]=temp[j-1]+temp[j];
            }
            temp = res;
        }
        return res;
    }
};