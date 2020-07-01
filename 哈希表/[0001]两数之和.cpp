/*
����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣

ʾ��:
���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9
���Է��� [0, 1]
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

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<double, int> buffer;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            auto TargetKey = buffer.find(double(target) - double(nums[i]));
            if (TargetKey != buffer.end())
            {
                res.push_back(i);
                res.push_back((*TargetKey).second);
            }
            else
                buffer[double(nums[i])] = i;
        }
        return res;
    }
};