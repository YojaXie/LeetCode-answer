/*
����һ������������ַ������������������ַ�����
�������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string �����ظ� k �Ρ�ע�� k ��֤Ϊ��������
�������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�
���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k �����粻������� 3a �� 2[4] �����롣

ʾ�� 1��
���룺s = "3[a]2[bc]"
�����"aaabcbc"

ʾ�� 2��
���룺s = "3[a2[c]]"
�����"accaccacc"

ʾ�� 3��
���룺s = "2[abc]3[cd]ef"
�����"abcabccdcdcdef"

ʾ�� 4��
���룺s = "abc3[cd]xyz"
�����"abccdcdcdxyz"
*/

#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

class Solution
{
public:
	string decodeString(string s)
	{
		stack<char> buffer;
		string res;
		for (char str : s)
		{
			if (str == ']')
			{
				int times = 0;
				string temp;
				int k = 0;
				while (buffer.top() != '[')
				{
					temp.push_back(buffer.top());
					buffer.pop();
				}
				buffer.pop();
				while (buffer.top() >= '0' && buffer.top() <= '9')
				{
					times = times + int(buffer.top() - '0') * pow(10, k);
					k++;
					buffer.pop();
					if (buffer.empty()) break;
				}
				for (int i = 0; i < times; i++)
				{
					for (int j = temp.size()-1; j >= 0; j--)
					{
						buffer.push(temp[j]);
					}
				}
			}
			else
			{
				buffer.push(str);
			}
		}
		while (!buffer.empty())
		{
			res.push_back(buffer.top());
			buffer.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
