/*
����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:
����: "A man, a plan, a canal: Panama"
���: true

ʾ�� 2:
����: "race a car"
���: false
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Solution 
{
public:
	bool isPalindrome(string s) 
	{
		int i = 0, j = s.size()-1;
		while (i < j)
		{
			if (s[i] == s[j] || (s[i] + 32 == s[j] && s[i]>'9') || (s[i] == s[j] + 32 && s[j]>'9') || 
				(s[i] < 48 || (s[i] > 57 && s[i] < 65) || (s[i] > 90 && s[i] < 97) || s[i] > 122) && 
				(s[j] < 48 || (s[j] > 57 && s[j] < 65) || (s[j] > 90 && s[j] < 97) || s[j] > 122))
			{
				i++; j--;
			}
			else if (s[i] < 48 || (s[i] > 57 && s[i] < 65) || (s[i] > 90 && s[i] < 97) || s[i] > 122) i++;
			else if (s[j] < 48 || (s[j] > 57 && s[j] < 65) || (s[j] > 90 && s[j] < 97) || s[j] > 122) j--;
			else return false;
		}
		return true;
	}
};