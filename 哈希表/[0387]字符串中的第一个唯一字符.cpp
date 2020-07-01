/*
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��

ʾ����
s = "leetcode"
���� 0
s = "loveleetcode"
���� 2

��ʾ������Լٶ����ַ���ֻ����Сд��ĸ��
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