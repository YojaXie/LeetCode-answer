/*
����һ���Ǹ����� k������ k �� 33������������ǵĵ� k �С�

����������У�ÿ�����������Ϸ������Ϸ������ĺ͡�

ʾ��:

����: 3
���: [1,3,3,1]
���ף�

������Ż�����㷨�� O(k) �ռ临�Ӷ���
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