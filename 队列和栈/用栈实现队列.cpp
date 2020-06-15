/*
ʹ��ջʵ�ֶ��е����в�����
push(x) -- ��һ��Ԫ�ط�����е�β����
pop() -- �Ӷ����ײ��Ƴ�Ԫ�ء�
peek() -- ���ض����ײ���Ԫ�ء�
empty() -- ���ض����Ƿ�Ϊ�ա�

ʾ��:
MyQueue queue = new MyQueue();
queue.push(1);
queue.push(2);
queue.peek();  // ���� 1
queue.pop();   // ���� 1
queue.empty(); // ���� false

˵��:
��ֻ��ʹ�ñ�׼��ջ���� -- Ҳ����ֻ�� push to top, peek/pop from top, size, �� is empty �����ǺϷ��ġ�
����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ��������
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class MyQueue 
{
private:
	stack<int> data;
	stack<int> datareverse;
public:
	/** Initialize your data structure here. */
	MyQueue() 
	{

	}

	/** Push element x to the back of queue. */
	void push(int x) 
	{
		data.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() 
	{
		while(!data.empty())
		{
			datareverse.push(data.top());
			data.pop();
		}
		int res = datareverse.top();
		datareverse.pop();
		while (!datareverse.empty())
		{
			data.push(datareverse.top());
			datareverse.pop();
		}
		return res;
	}

	/** Get the front element. */
	int peek() 
	{
		while (!data.empty())
		{
			datareverse.push(data.top());
			data.pop();
		}
		int res = datareverse.top();
		while (!datareverse.empty())
		{
			data.push(datareverse.top());
			datareverse.pop();
		}
		return res;
	}

	/** Returns whether the queue is empty. */
	bool empty() 
	{
		if (data.empty())
			return true;
		else return false;
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */