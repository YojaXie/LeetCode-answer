/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

示例：
s = "leetcode"
返回 0
s = "loveleetcode"
返回 2

提示：你可以假定该字符串只包含小写字母。
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
    int firstUniqChar(string s) 
    {
        unordered_map<char, int> CharMapNum;
        for (char chr : s)
        {
            if (CharMapNum.count(chr) > 0)
            {
                CharMapNum[chr] += 1;
            }
            else
            {
                CharMapNum[chr] = 1;
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (CharMapNum[s[i]] == 1)
                return i;
        }
        return -1;
    }
};