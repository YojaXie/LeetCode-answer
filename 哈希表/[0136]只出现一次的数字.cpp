/*
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

˵����
����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����

ʾ�� 1:
����: [2,2,1]
���: 1

ʾ�� 2:
����: [4,1,2,1,2]
���: 4
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
    int singleNumber(vector<int>& nums) 
    {
        int res = 0;
        for (auto num : nums)
        {
            res = res ^ num;
        }
        return res;
    }
};