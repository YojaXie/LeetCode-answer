/*
����һ������ M x N ��Ԫ�صľ���M �У�N �У������ԶԽ��߱�����˳�򷵻���������е�����Ԫ�أ��Խ��߱�������ͼ��ʾ��

ʾ��:

����:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

���:  [1,2,4,7,5,3,6,8,9]

˼·�� ���� ��+1����+1��-1����+1,��-1��+1����-1��+1
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
