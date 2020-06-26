/*
����һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�

����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�

ʾ��:

����: 5
���:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> res(numRows, vector<int>());
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i - 1 < 0 || j - 1 < 0 || j >= i)
                    res[i].push_back(1);
                else
                    res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
        }
        return res;
    }
};