/*
�����沨����ʾ��������ʽ��ֵ��
��Ч����������� +, -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��

˵����
��������ֻ�����������֡�
�����沨�����ʽ������Ч�ġ����仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������

ʾ�� 1��
����: ["2", "1", "+", "3", "*"]
���: 9
����: ((2 + 1) * 3) = 9

ʾ�� 2��
����: ["4", "13", "5", "/", "+"]
���: 6
����: (4 + (13 / 5)) = 6

ʾ�� 3��
����: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
���: 22
����:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
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
    int evalRPN(vector<string>& tokens)
    {
        int temp;
        stack<int> buffer;
        for (string str : tokens)
        {
            if (str != "+" && str != "-" && str != "*" && str != "/")
            {
                if (str[0] == '-')
                {
                    temp = -int(str[1] - '0');
                }
                else
                    temp = str[0] - '0';
                buffer.push(temp);
            }
            else
            {
                int num2 = buffer.top();
                buffer.pop();
                int num1 = buffer.top();
                buffer.pop();
                if (str == "+") buffer.push(num1 + num2);
                if (str == "-") buffer.push(num1 - num2);
                if (str == "*") buffer.push(num1 * num2);
                if (str == "/") buffer.push(num1 / num2);
            }
        }
        return buffer.top();
    }
};

int main()
{
    vector<string> tokens;
    tokens.push_back("10");
    tokens.push_back("6");
    tokens.push_back("9");
    tokens.push_back("3");
    tokens.push_back("+");
    tokens.push_back("-11");
    tokens.push_back("*");
    tokens.push_back("");
    tokens.push_back("+");
}