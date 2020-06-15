/*
ʹ�ö���ʵ��ջ�����в�����
push(x) -- Ԫ�� x ��ջ
pop() -- �Ƴ�ջ��Ԫ��
top() -- ��ȡջ��Ԫ��
empty() -- ����ջ�Ƿ�Ϊ��

ע��:
��ֻ��ʹ�ö��еĻ�������-- Ҳ���� push to back, peek/pop from front, size, �� is empty ��Щ�����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���� deque��˫�˶��У���ģ��һ������ , ֻҪ�Ǳ�׼�Ķ��в������ɡ�
����Լ������в���������Ч�ģ�����, ��һ���յ�ջ������� pop ���� top ��������
*/

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>

using namespace std;

class MyStack 
{
private:
	deque<int> data;
	deque<int> datareverse;

public:
	/** Initialize your data structure here. */
	MyStack() 
	{

	}

	/** Push element x onto stack. */
	void push(int x) 
	{
		data.push_back(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() 
	{
		int datasize = data.size();
		for(int i=0;i<datasize -1;i++)
		{
			datareverse.push_back(data.front());
			data.pop_front();
		}
		int res = data.front();
		data.pop_front();
		while (!datareverse.empty())
		{
			data.push_back(datareverse.front());
			datareverse.pop_front();
		}
		return res;
	}

	/** Get the top element. */
	int top() 
	{
		int datasize = data.size();
		for (int i = 0; i < datasize - 1; i++)
		{
			datareverse.push_back(data.front());
			data.pop_front();
		}
		int res = data.front();
		datareverse.push_back(data.front());
		data.pop_front();
		while (!datareverse.empty())
		{
			data.push_back(datareverse.front());
			datareverse.pop_front();
		}
		return res;
	}

	/** Returns whether the stack is empty. */
	bool empty() 
	{
		if (data.empty()) return true;
		else return false;
	}
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
int main()
{
	MyStack* obj = new MyStack();
	obj->push(1);
	obj->push(2);
	obj->push(3);
	//int param_2 = obj->pop();
	int param_3 = obj->top();
	bool param_4 = obj->empty();
	return 0;
}