/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string res;
        if (strs.empty())
            return res;
        int veclength = strs.size();
        int strlength = strs[0].size();
        bool flag = true;
        for (int i = 0; i < strlength; i++)
        {
            flag = true;
            for (int j = 0; j < veclength-1; j++)
            {
                if (i >= strs[j].size() || i >= strs[j + 1].size())
                {
                    flag = false;
                    break;
                }
                if (strs[j][i] != strs[j + 1][i])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
            res.push_back(strs[0][i]);

        }
        return res;
    }
};