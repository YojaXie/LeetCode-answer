/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

ʾ�� 1��

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�
ʾ�� 2��

����: "cbbd"
���: "bb"
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
