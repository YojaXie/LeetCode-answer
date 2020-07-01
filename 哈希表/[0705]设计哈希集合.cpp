/*
不使用任何内建的哈希表库设计一个哈希集合
具体地说，你的设计应该包含以下的功能
add(value)：向哈希集合中插入一个值。
contains(value) ：返回哈希集合中是否存在这个值。
remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

示例:
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);
hashSet.add(2);
hashSet.contains(1);    // 返回 true
hashSet.contains(3);    // 返回 false (未找到)
hashSet.add(2);
hashSet.contains(2);    // 返回 true
hashSet.remove(2);
hashSet.contains(2);    // 返回  false (已经被删除)

注意：
所有的值都在 [0, 1000000]的范围内。
操作的总数目在[1, 10000]范围内。
不要使用内建的哈希集合库。
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
