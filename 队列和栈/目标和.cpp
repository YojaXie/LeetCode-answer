/*
����һ���Ǹ��������飬a1, a2, ..., an, ��һ��Ŀ������S������������������ + �� -�����������е�����һ���������㶼���Դ� + �� -��ѡ��һ�����������ǰ�档
���ؿ���ʹ���������ΪĿ���� S ��������ӷ��ŵķ�������

ʾ����
���룺nums: [1, 1, 1, 1, 1], S: 3
�����5
���ͣ�
-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

һ����5�ַ���������Ŀ���Ϊ3��

��ʾ��
����ǿգ��ҳ��Ȳ��ᳬ�� 20 ��
��ʼ������ĺͲ��ᳬ�� 1000 ��
��֤���ص����ս���ܱ� 32 λ�������¡�
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int res = 0;
        DFS(res, 0, 0, nums, S);
        return res;
    }
    void DFS(int& res, int sum, int i, vector<int>& nums, int S)
    {
        if (i == nums.size())
        {
            if (sum == S)
                res = res + 1;
        }
        else
        {
            DFS(res, sum + nums[i], i + 1, nums, S);
            DFS(res, sum - nums[i], i + 1, nums, S);
        }
    }
};