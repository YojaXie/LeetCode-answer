/*
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��

ʾ�� 1:

����: ["flower","flow","flight"]
���: "fl"
ʾ�� 2:

����: ["dog","racecar","car"]
���: ""
����: ���벻���ڹ���ǰ׺��
˵��:

��������ֻ����Сд��ĸ a-z ��
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