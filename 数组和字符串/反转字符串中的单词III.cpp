/*
����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��

ʾ�� 1:

����: "Let's take LeetCode contest"
���: "s'teL ekat edoCteeL tsetnoc"
ע�⣺���ַ����У�ÿ�������ɵ����ո�ָ��������ַ����в������κζ���Ŀո�
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