/*
���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
push(x) ���� ��Ԫ�� x ����ջ�С�
pop() ���� ɾ��ջ����Ԫ�ء�
top() ���� ��ȡջ��Ԫ�ء�
getMin() ���� ����ջ�е���СԪ�ء�

ʾ��:
���룺
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

�����
[null,null,null,null,-3,null,0,-2]

���ͣ�
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.getMin();   --> ���� -2.


��ʾ��
pop��top �� getMin ���������� �ǿ�ջ �ϵ��á�
*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MinStack 
{
private:
	vector<pair<int, int>> data;
	int MinNum;

public:
	/** initialize your data structure here. */
	MinStack() 
	{
		MinNum = INT_MAX;
	}
	void push(int x) 
	{
		if (data.empty())
			data.push_back({ x, x });
		else
		{
			MinNum = data.back().second;
			MinNum = min(x, MinNum);
			data.push_back({ x, MinNum });
		}
	}
	void pop() 
	{
		if (!data.empty())
			data.pop_back();
	}
	int top() 
	{
		if (!data.empty())
			return data.back().first;
		return -1;
	}
	int getMin() 
	{
		if (!data.empty())
			return data.back().second;
		return -1;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
