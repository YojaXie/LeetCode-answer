/*
����һ�����������һ������ k���ж��������Ƿ����������ͬ������ i �� j��
ʹ�� nums [i] = nums [j]������ i �� j �Ĳ�� ����ֵ ����Ϊ k��

ʾ�� 1:
����: nums = [1,2,3,1], k = 3
���: true

ʾ�� 2:
����: nums = [1,0,1,1], k = 1
���: true

ʾ�� 3:
����: nums = [1,2,3,1,2,3], k = 2
���: false
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
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> NumMapIndex;
        for (int i = 0; i < nums.size(); i++)
        {
            if (NumMapIndex.count(nums[i]) > 0)
            {
                if (i - NumMapIndex[nums[i]] <= k)
                    return true;
                else
                    NumMapIndex[nums[i]] = i;
            }
            else
                NumMapIndex[nums[i]] = i;
        }
        return false;
    }
};