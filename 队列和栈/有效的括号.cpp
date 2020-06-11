/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true
*/



#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

class Solution 
{
public:
	bool isValid(string s) 
	{
		stack<char> buffer;
		for (char str : s)
		{
			if (str == '(' || str == '{' || str == '[')
				buffer.push(str);
			if (str == ')' || str == '}' || str == ']')
			{
				if (str == ')') str = '(';
				if (str == ']') str = '[';
				if (str == '}') str = '{';
				if (buffer.empty()) return false;
				if (buffer.top() == str) buffer.pop();
				else break;
			}
		}
		if (buffer.empty()) return true;
		return false;
	}
};