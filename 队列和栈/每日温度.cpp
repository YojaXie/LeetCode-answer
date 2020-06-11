/*
�����ÿ�� ���� �б���������һ���б���Ӧλ�õ����Ϊ��Ҫ��۲⵽���ߵ����£�������Ҫ�ȴ��������������������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
���磬����һ���б� temperatures = [73, 74, 75, 71, 69, 72, 76, 73]��������Ӧ���� [1, 1, 4, 2, 1, 1, 0, 0]��
��ʾ������ �б��ȵķ�Χ�� [1, 30000]��ÿ�����µ�ֵ�ľ�Ϊ���϶ȣ������� [30, 100] ��Χ�ڵ�������
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution 
{
public:
	vector<int> dailyTemperatures(vector<int>& T) 
	{
		vector<int> res;
		res.resize(T.size());
		stack<int> buffer;
		buffer.push(T.size()-1);
		for (int i = int(T.size()) - 2; i >= 0; i--)
		{
			while (T[i] >= T[buffer.top()])
			{
				buffer.pop();
				if (buffer.empty())
				{
					res[i] = 0;
					break;
				}
			}
			if(!buffer.empty())
				res[i] = buffer.top() - i;
			buffer.push(i);
		}
		return res;
	}
};
