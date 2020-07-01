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
MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);
hashMap.put(2, 2);
hashMap.get(1);            // ���� 1
hashMap.get(3);            // ���� -1 (δ�ҵ�)
hashMap.put(2, 1);         // �������е�ֵ
hashMap.get(2);            // ���� 1
hashMap.remove(2);         // ɾ����Ϊ2������
hashMap.get(2);            // ���� -1 (δ�ҵ�)

ע�⣺
���е�ֵ���� [0, 1000000]�ķ�Χ�ڡ�
����������Ŀ��[1, 10000]��Χ�ڡ�
��Ҫʹ���ڽ��Ĺ�ϣ�⡣
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;

class MyHashMap 
{
private:
    vector<int> map;
public:
    /** Initialize your data structure here. */
    MyHashMap() 
    {
        map.resize(1000001, -1);
    }

    /** value will always be non-negative. */
    void put(int key, int value) 
    {
        int index = Key2Index(key);
        map[index] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) 
    {
        int index = Key2Index(key);
        return map[index];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) 
    {
        int index = Key2Index(key);
        map[index] = -1;
    }
    int Key2Index(int key)
    {
        return key % 1000001;
    }
};