/*
给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:
输入: s = "egg", t = "add"
输出: true

示例 2:
输入: s = "foo", t = "bar"
输出: false

示例 3:
输入: s = "paper", t = "title"
输出: true
说明:
你可以假设 s 和 t 具有相同的长度。
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
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, char> SMapT;
        unordered_map<char, char> TMapS;
        for (int i = 0; i < s.size(); i++)
        {
            if (SMapT.count(s[i]) > 0)
            {
                if (SMapT[s[i]] != t[i]) return false;
            }
            else
            {
                SMapT[s[i]] = t[i];
            }
            if (TMapS.count(t[i]) > 0)
            {
                if (TMapS[t[i]] != s[i]) return false;
            }
            else
            {
                TMapS[t[i]] = s[i];
            }
        }
        return true;
    }
};