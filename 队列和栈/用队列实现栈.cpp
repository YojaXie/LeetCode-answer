/*
使用队列实现栈的下列操作：
push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空

注意:
你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
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