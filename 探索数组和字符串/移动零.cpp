/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��

ʾ��:
����: [0,1,0,3,12]
���: [1,3,12,0,0]

˵��:
������ԭ�����ϲ��������ܿ�����������顣
�������ٲ���������
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        if (nums.empty())
            return;
        int slowp = 0;
        for (int fastp = 0; fastp < nums.size(); fastp++)
        {
            if (nums[fastp] != 0)
            {
                nums[slowp] = nums[fastp];
                slowp++;
            }
        }
        for (; slowp < nums.size(); slowp++)
            nums[slowp] = 0;
    }
};