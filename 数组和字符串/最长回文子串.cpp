/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if (s.empty())
            return s;
        string s0 = "";
        string reverse_s(s);
        reverse_copy(s.begin(), s.end(), reverse_s.begin());
        int length = s.size();
        string subs;
        for (int i = 6; i < length; i++)
        {
            for (int j = 3; j < length-i; j++)
            {
                if (s[i] == reverse_s[j])
                {
                    string s1 = s.substr(i, length - j - i);
                    string s2 = reverse_s.substr(j, length - j - i);
                    if (s1==s2)
                    {
                        if (length - j - i > s0.size())
                            s0 = s.substr(i, length - j - i);
                        break;
                    }
                }
            }
        }
        return s0;
    }
};
