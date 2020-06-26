/*
��дһ���㷨����M �� N������ĳ��Ԫ��Ϊ0���������ڵ����������㡣
ʾ�� 1��

���룺
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
�����
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
ʾ�� 2��

���룺
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
�����
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