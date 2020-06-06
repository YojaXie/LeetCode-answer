/*
给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：

输入: "the sky is blue"
输出: "blue is sky the"
示例 2：

输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：

输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。


说明：

无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
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
		if (s.empty())
			return s;
		string reverse_s = s;
		string temp=s;
		reverse(reverse_s.begin(), reverse_s.end());
		string ans=s;
		ans.clear();
		temp.clear();
		for (int i = 0; i < s.size(); i++)
		{
			if (temp.size() == 0 && reverse_s[i]==' ')
				continue;
			if (reverse_s[i] == ' ' ||  i==s.size()-1)
			{
				if(i == s.size() - 1 && reverse_s[i] != ' ')
					temp.push_back(reverse_s[i]);
				reverse(temp.begin(), temp.end());
				ans += temp + ' ';
				temp.clear();
				continue;
			}
			temp.push_back(reverse_s[i]);
		}
		if(!ans.empty())
			ans.pop_back();
		return ans;
	}
};

int main()
{
	string test = " 1";
	string ans;
	ans = Solution().reverseWords(test);
	cout << ans << endl;
}