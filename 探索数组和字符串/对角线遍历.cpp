/*
给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。

示例:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

输出:  [1,2,4,7,5,3,6,8,9]

思路： 过程 列+1，行+1列-1，行+1,行-1列+1，行-1列+1
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
        vector<int> res;
        if (matrix.empty())
            return res;
        int i = 0;
        int j = 0;
        res.push_back(matrix[i][j]);
        int m = matrix.size();
        int n = matrix[0].size();
        int nums = m * n;
        bool up = true;
        for (int k = 1; k < nums; k++)
        {
            if (up)
            {
                i--;
                j++;
                if (i < 0 && j<n)
                {
                    i++;
                    up = false;
                }
                if (j >= n)
                {
                    up = false;
                    i++;
                    j--;
                    i++;
                }
                res.push_back(matrix[i][j]);
            }
            else
            {
                i++;
                j--;
                if (j < 0 && i<m)
                {
                    j++;
                    up = true;
                }
                if (i >= m)
                {
                    up = true;
                    i--;
                    j++;
                    j++;
                }
                res.push_back(matrix[i][j]);
            }
        }
        return res;
    }
};
