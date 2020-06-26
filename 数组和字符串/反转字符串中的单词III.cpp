/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc"
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


class Solution 
{
public:
    string reverseWords(string s) 
    {
        string temp;
        string res;
        int slowp = 0;
        int fastp = 0;
        for (; fastp != s.size(); fastp++)
        {
            if (s[fastp] == ' ')
            {
                temp.assign(s, slowp, fastp - slowp);
                reverse(temp.begin(), temp.end());
                res.insert(slowp, temp);
                res.push_back(s[fastp]);
                slowp = fastp + 1;
            }
        }
        temp.assign(s, slowp, fastp - slowp);
        reverse(temp.begin(), temp.end());
        res.insert(slowp, temp);
        return res;
    }
};