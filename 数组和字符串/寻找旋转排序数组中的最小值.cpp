/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��

���ҳ�������С��Ԫ�ء�

����Լ��������в������ظ�Ԫ�ء�

ʾ�� 1:

����: [3,4,5,1,2]
���: 1
ʾ�� 2:

����: [4,5,6,7,0,1,2]
���: 0
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        if (nums[0] <= nums[nums.size() - 1])
            return nums[0];
        int lefti = 0;
        int temp = nums[0];
        for (int righti = nums.size() - 1; lefti < righti;)
        {
            if (nums[(righti + lefti) / 2] >= temp)
                lefti = (righti + lefti) / 2 + 1;
            if (nums[(righti + lefti) / 2] < temp)
                righti = (righti + lefti) / 2;
        }
        return nums[lefti];
    }
};