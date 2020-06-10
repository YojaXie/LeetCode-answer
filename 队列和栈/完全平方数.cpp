/*
���������� n���ҵ����ɸ���ȫƽ���������� 1, 4, 9, 16, ...��ʹ�����ǵĺ͵��� n������Ҫ����ɺ͵���ȫƽ�����ĸ������١�

ʾ�� 1:
����: n = 12
���: 3
����: 12 = 4 + 4 + 4.

ʾ�� 2:
����: n = 13
���: 2
����: 13 = 4 + 9.
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