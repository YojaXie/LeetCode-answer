/*
���һ���ҵ��������е�K��Ԫ�ص��ࣨclass����ע���������ĵ�K��Ԫ�أ����ǵ�K����ͬ��Ԫ�ء�
��� KthLargest ����Ҫһ��ͬʱ�������� k ����������nums �Ĺ��������������������еĳ�ʼԪ�ء�
ÿ�ε��� KthLargest.add�����ص�ǰ�������е�K���Ԫ�ء�

ʾ��:
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
˵��:
����Լ��� nums �ĳ��ȡ� k-1 ��k �� 1��
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class KthLargest 
{
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> buffer;

public:
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;
        for (int num : nums)
        {
            buffer.push(num);
            if (buffer.size() > k) buffer.pop();
        }
    }

    int add(int val) 
    {
        buffer.push(val);
        if (buffer.size() > this->k) buffer.pop();
        return buffer.top();
    }
};