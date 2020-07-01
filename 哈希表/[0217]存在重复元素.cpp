/*
不使用任何内建的哈希表库设计一个哈希集合
具体地说，你的设计应该包含以下的功能
add(value)：向哈希集合中插入一个值。
contains(value) ：返回哈希集合中是否存在这个值。
remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。

示例:
不使用任何内建的哈希表库设计一个哈希映射
具体地说，你的设计应该包含以下的功能
put(key, value)：向哈希映射中插入(键,值)的数值对。如果键对应的值已经存在，更新这个值。
get(key)：返回给定的键所对应的值，如果映射中不包含这个键，返回-1。
remove(key)：如果映射中存在这个键，删除这个数值对。

示例：
给定一个整数数组，判断是否存在重复元素
如果任意一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

示例 1:
输入: [1,2,3,1]
输出: true

示例 2:
输入: [1,2,3,4]
输出: false

示例 3:
输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
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