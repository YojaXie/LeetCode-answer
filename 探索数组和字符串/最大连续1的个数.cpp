/*
����һ�����������飬 ���������������1�ĸ�����

ʾ�� 1:

����: [1,1,0,1,1,1]
���: 3
����: ��ͷ����λ��������λ��������1�������������1�ĸ����� 3.
ע�⣺

���������ֻ���� 0 ��1��
��������ĳ��������������Ҳ����� 10,000��
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxnum = 0;
        for (int i = 0, j = -1; i <= nums.size(); i++)
        {
            if (i == nums.size())
            {
                maxnum = max(i - j - 1, maxnum);
                j = i;
                break;
            }
            if (nums[i] == 0)
            {
                maxnum = max(i - j - 1, maxnum);
                j = i;
            }
        }
        return maxnum;
    }
};