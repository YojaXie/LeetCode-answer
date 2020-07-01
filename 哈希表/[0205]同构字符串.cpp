/*
���������ַ��� s �� t���ж������Ƿ���ͬ���ġ�
��� s �е��ַ����Ա��滻�õ� t ����ô�������ַ�����ͬ���ġ�
���г��ֵ��ַ�����������һ���ַ��滻��ͬʱ�����ַ���˳�������ַ�����ӳ�䵽ͬһ���ַ��ϣ����ַ�����ӳ���Լ�����

ʾ�� 1:
����: s = "egg", t = "add"
���: true

ʾ�� 2:
����: s = "foo", t = "bar"
���: false

ʾ�� 3:
����: s = "paper", t = "title"
���: true
˵��:
����Լ��� s �� t ������ͬ�ĳ��ȡ�
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