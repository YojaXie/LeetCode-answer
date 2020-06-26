/*
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        vector<int> index;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    index.push_back(i);
                    index.push_back(j);
                }
            }
        }
        if (index.empty())
            return;
        int length = index.size();
        for (int k = 0; k < length; k=k+2)
        {
            int hang = index[k];
            int lie = index[k+1];
            for (int j = 0; j < n; j++)
                matrix[hang][j] = 0;
            for (int i = 0; i < m; i++)
                matrix[i][lie] = 0;
        }
    }
};