/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false
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