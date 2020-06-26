/*
����һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ�����С�����������飬�������䳤�ȡ���������ڷ������������������飬���� 0��

ʾ��:

����: s = 7, nums = [2,3,1,2,4,3]
���: 2
����: ������ [4,3] �Ǹ������µĳ�����С�����������顣
����:

������Ѿ������O(n) ʱ�临�ӶȵĽⷨ, �볢�� O(n log n) ʱ�临�ӶȵĽⷨ��
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int minlen = INT_MAX;
        int sum = 0;
        bool flag = false;
        for (int i = -1, j = -1; i < int(nums.size()); )
        {
            if (sum < s)
            {
                i++;
                if (i == nums.size())
                    break;
                sum += nums[i];
            }
            if (sum >= s)
            {
                flag = true;
                minlen = min(minlen, i - j);
                j++;
                sum -= nums[j];
            }
        }
        if (!flag)
            return 0;
        return minlen;
    }
};
