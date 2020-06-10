/*
������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣
��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��

���ʵ��Ӧ��֧�����²�����
MyCircularQueue(k): �����������ö��г���Ϊ k ��
Front: �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� -1 ��
Rear: ��ȡ��βԪ�ء��������Ϊ�գ����� -1 ��
enQueue(value): ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
deQueue(): ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
isEmpty(): ���ѭ�������Ƿ�Ϊ�ա�
isFull(): ���ѭ�������Ƿ�������

ʾ����
MyCircularQueue circularQueue = new MyCircularQueue(3); // ���ó���Ϊ 3
circularQueue.enQueue(1);  // ���� true
circularQueue.enQueue(2);  // ���� true
circularQueue.enQueue(3);  // ���� true
circularQueue.enQueue(4);  // ���� false����������
circularQueue.Rear();  // ���� 3
circularQueue.isFull();  // ���� true
circularQueue.deQueue();  // ���� true
circularQueue.enQueue(4);  // ���� true
circularQueue.Rear();  // ���� 4

��ʾ��
���е�ֵ���� 0 �� 1000 �ķ�Χ�ڣ�
���������� 1 �� 1000 �ķ�Χ�ڣ�
�벻Ҫʹ�����õĶ��п⡣
*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MyCircularQueue 
{
private:
	vector<int> data;
	int head;
	int tail;
	int size;

public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) 
	{
		this->data.resize(k);
		size = k;
		head = -1;
		tail = -1;
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) 
	{
		if (this->isFull())
			return false;
		if (this->isEmpty())
			head = 0;
		tail = (tail + 1) % size;
		data[tail] = value;
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() 
	{
		if (this->isEmpty())
			return false;
		if (head == tail)
		{
			head = -1;
			tail = -1;
			return true;
		}
		head = (head + 1) % size;
		return true;
	}

	/** Get the front item from the queue. */
	int Front() 
	{
		if (this->isEmpty())
			return -1;
		return data[head];
	}

	/** Get the last item from the queue. */
	int Rear() 
	{
		if (this->isEmpty())
			return -1;
		return data[tail];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() 
	{
		if (head == -1)
			return true;
		return false;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() 
	{
		if ((tail + 1) % size == head)
			return true;
		return false;
	}
};