/*
给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为 非空 字符串且只包含数字 1 和 0。

示例 1:
输入: a = "11", b = "1"
输出: "100"

示例 2:
输入: a = "1010", b = "1011"
输出: "10101"

提示：
每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        char carry = '0';
        string res;
        int i = a.size() - 1, j = b.size() - 1;
        for (; i >= 0 && j >= 0; i--, j--)
        {
            if (a[i] == '1' && b[j] == '1')
            {
                res.push_back(carry);
                carry = '1';
            }
            else if ((a[i] == '1' && b[j] == '0') || (a[i] == '0' && b[j] == '1'))
            {
                if (carry == '1')
                {
                    res.push_back('0');
                    carry = '1';
                }
                else
                {
                    res.push_back('1');
                    carry = '0';
                }
            }
            else
            {
                res.push_back(carry);
                carry = '0';
            }
        }
        while (i >= 0)
        {
            if (carry == '1' && a[i] == '1')
            {
                res.push_back('0');
                carry = '1';
            }
            else
            {
                res.push_back(carry - '0' + a[i]);
                carry = '0';
            }
            i--;
        }
        while (j >= 0)
        {
            if (carry == '1' && b[j] == '1')
            {
                res.push_back('0');
                carry = '1';
            }
            else
            {
                res.push_back(carry - '0' + b[j]);
                carry = '0';
            }
            j--;
        }
        if (carry == '1') res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};