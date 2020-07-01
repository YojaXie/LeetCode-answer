/*
��ʹ���κ��ڽ��Ĺ�ϣ������һ����ϣ����
�����˵��������Ӧ�ð������µĹ���
add(value)�����ϣ�����в���һ��ֵ��
contains(value) �����ع�ϣ�������Ƿ�������ֵ��
remove(value)��������ֵ�ӹ�ϣ������ɾ���������ϣ������û�����ֵ��ʲôҲ������

ʾ��:
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);
hashSet.add(2);
hashSet.contains(1);    // ���� true
hashSet.contains(3);    // ���� false (δ�ҵ�)
hashSet.add(2);
hashSet.contains(2);    // ���� true
hashSet.remove(2);
hashSet.contains(2);    // ����  false (�Ѿ���ɾ��)

ע�⣺
���е�ֵ���� [0, 1000000]�ķ�Χ�ڡ�
����������Ŀ��[1, 10000]��Χ�ڡ�
��Ҫʹ���ڽ��Ĺ�ϣ���Ͽ⡣
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

class MyHashSet 
{
private:
    vector<int> key;
public:
    /** Initialize your data structure here. */
    MyHashSet() 
    {
        key.resize(1000001, -1);
    }

    void add(int key) 
    {
        this->key[Key2Index(key)] = key;
    }

    void remove(int key) 
    {
        int index = Key2Index(key);
        if (this->key[index] != -1)
            this->key[index] = -1;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) 
    {
        int index = Key2Index(key);
        if (this->key[index] == key)
            return true;
        else
            return false;
    }
    int Key2Index(int key)
    {
        return key % 1000001;
    }
};
