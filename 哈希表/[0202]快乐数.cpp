/*
��дһ���㷨���ж�һ���� n �ǲ��ǿ�������
��������������Ϊ������һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���ͣ�
Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1����� ���Ա�Ϊ  1����ô��������ǿ�������
��� n �ǿ������ͷ��� True �����ǣ��򷵻� False ��

ʾ����
���룺19
�����true
���ͣ�
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;
// MAX_INT = 2147483647
class Solution 
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> used;
        while (used.count(n) == 0)
        {
            used.insert(n);
            int sum = 0;
            for (int i = 9; i >= 0; i--)
            {
                int NumIth = (n / int(pow(10, i))) % 10;
                if (NumIth != 0)
                {
                    while (i >= 0)
                    {
                        NumIth = (n / int(pow(10, i))) % 10;
                        sum += NumIth * NumIth;
                        i--;
                    }
                }
            }
            n = sum;
            if (sum == 1) return true;
        }
        return false;
    }
};