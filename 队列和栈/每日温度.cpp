/*
�����ÿ�� ���� �б���������һ���б���Ӧλ�õ����Ϊ��Ҫ��۲⵽���ߵ����£�������Ҫ�ȴ��������������������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
���磬����һ���б� temperatures = [73, 74, 75, 71, 69, 72, 76, 73]��������Ӧ���� [1, 1, 4, 2, 1, 1, 0, 0]��
��ʾ������ �б��ȵķ�Χ�� [1, 30000]��ÿ�����µ�ֵ�ľ�Ϊ���϶ȣ������� [30, 100] ��Χ�ڵ�������
*/



#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<list>

using namespace std;

class Solution 
{
public:
	vector<int> dailyTemperatures(vector<int>& T) 
	{
		vector<int> res;
		res.resize(T.size());
		stack<int> buffer;
		vector<int> buffer_out;
		for (int i : T) buffer.push(i);
		for (int i = T.size()-1; i >=0; i--)
		{
			for (int j = buffer_out.size()-1; j >= 0; j--)
			{
				if (buffer.top() < buffer_out[j])
				{
					res[i] = buffer_out.size() - j;
					break;
				}
			}
			buffer_out.push_back(buffer.top());
			buffer.pop();
		}
		return res;
	}
};

int main()
{
	vector<int> T;
	T.push_back(73);
	T.push_back(74);
	T.push_back(75);
	T.push_back(71);
	T.push_back(69);
	T.push_back(72);
	T.push_back(76);
	T.push_back(73);
	vector<int> res = Solution().dailyTemperatures(T);

	return 0;
}