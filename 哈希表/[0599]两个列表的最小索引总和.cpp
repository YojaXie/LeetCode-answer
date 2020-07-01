/*
����Andy��Doris�������ʱѡ��һ�Ҳ������������Ƕ���һ����ʾ��ϲ���������б�ÿ���������������ַ�����ʾ��
����Ҫ�������������ٵ��������ҳ����ǹ�ͬϲ���Ĳ����� ����𰸲�ֹһ������������д𰸲��Ҳ�����˳�� ����Լ������Ǵ���һ���𰸡�

ʾ�� 1:
����:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
���: ["Shogun"]
����: ����Ψһ��ͬϲ���Ĳ����ǡ�Shogun����

ʾ�� 2:
����:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
���: ["Shogun"]
����: ���ǹ�ͬϲ���Ҿ�����С�����͵Ĳ����ǡ�Shogun����������С��������1(0+1)��

��ʾ:
�����б�ĳ��ȷ�Χ���� [1, 1000]�ڡ�
�����б��е��ַ����ĳ��Ƚ���[1��30]�ķ�Χ�ڡ�
�±��0��ʼ�����б�ĳ��ȼ�1��
�����б�û���ظ���Ԫ�ء�
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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
    {
        unordered_map<string, int> NameMap;
        vector<string> res;
        vector<string> EmptySwap;
        for (int i = 0; i < list1.size(); i++) NameMap[list1[i]] = i;
        int MinIndexSum = INT_MAX;
        for (int i = 0; i < list2.size(); i++)
        {
            if (NameMap.count(list2[i]) > 0)
            {
                int sum = i + NameMap[list2[i]];
                if (sum < MinIndexSum)
                {
                    MinIndexSum = sum;
                    res = EmptySwap;
                }
                if (sum == MinIndexSum)
                    res.push_back(list2[i]);
            }
        }
        return res;
    }
};