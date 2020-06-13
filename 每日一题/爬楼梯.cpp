/*
������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
ע�⣺���� n ��һ����������

ʾ�� 1��
���룺 2
����� 2
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 ��
2.  2 ��

ʾ�� 2��
���룺 3
����� 3
���ͣ� �����ַ�����������¥����
1.  1 �� + 1 �� + 1 ��
2.  1 �� + 2 ��
3.  2 �� + 1 ��

˼·�� ������쳲���������
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
    int climbStairs(int n) 
    {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int res;
        int temp1 = 1;
        int temp2 = 2;
        for (int i = 3; i <= n; i++)
        {
            res = temp1 + temp2;
            temp1 = temp2;
            temp2 = res;
        }
        return res;
    }
};