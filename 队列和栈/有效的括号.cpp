/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��
��Ч�ַ��������㣺
�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ע����ַ����ɱ���Ϊ����Ч�ַ�����

ʾ�� 1:
����: "()"
���: true

ʾ�� 2:
����: "()[]{}"
���: true

ʾ�� 3:
����: "(]"
���: false

ʾ�� 4:
����: "([)]"
���: false

ʾ�� 5:
����: "{[]}"
���: true
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