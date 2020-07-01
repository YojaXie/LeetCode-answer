/*
��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣ����
�����˵��������Ӧ�ð������µĹ���
add(value)�����ϣ�����в���һ��ֵ��
contains(value) �����ع�ϣ�������Ƿ�������ֵ��
remove(value)��������ֵ�ӹ�ϣ������ɾ���������ϣ������û�����ֵ��ʲôҲ������

ʾ��:
��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣӳ��
�����˵��������Ӧ�ð������µĹ���
put(key, value)�����ϣӳ���в���(��,ֵ)����ֵ�ԡ��������Ӧ��ֵ�Ѿ����ڣ��������ֵ��
get(key)�����ظ����ļ�����Ӧ��ֵ�����ӳ���в����������������-1��
remove(key)�����ӳ���д����������ɾ�������ֵ�ԡ�

ʾ����
����һ���������飬�ж��Ƿ�����ظ�Ԫ��
�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��

ʾ�� 1:
����: [1,2,3,1]
���: true

ʾ�� 2:
����: [1,2,3,4]
���: false

ʾ�� 3:
����: [1,1,1,3,3,4,3,2,4,2]
���: true
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
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> buffer;
        for (int num : nums)
        {
            if (buffer.count(num) > 0) return true;
            else buffer.insert(num);
        }
        return false;
    }
};