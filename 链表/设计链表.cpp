/*
��������ʵ�֡�������ѡ��ʹ�õ������˫�����������еĽڵ�Ӧ�þ����������ԣ�val �� next��val �ǵ�ǰ�ڵ��ֵ��next ��ָ����һ���ڵ��ָ��/���á����Ҫʹ��˫����������Ҫһ������ prev ��ָʾ�����е���һ���ڵ㡣���������е����нڵ㶼�� 0-index �ġ�

����������ʵ����Щ���ܣ�
get(index)����ȡ�����е� index ���ڵ��ֵ�����������Ч���򷵻�-1��
addAtHead(val)��������ĵ�һ��Ԫ��֮ǰ���һ��ֵΪ val �Ľڵ㡣������½ڵ㽫��Ϊ����ĵ�һ���ڵ㡣
addAtTail(val)����ֵΪ val �Ľڵ�׷�ӵ���������һ��Ԫ�ء�
addAtIndex(index,val)���������еĵ� index ���ڵ�֮ǰ���ֵΪ val  �Ľڵ㡣��� index ��������ĳ��ȣ���ýڵ㽫���ӵ������ĩβ����� index ���������ȣ��򲻻����ڵ㡣���indexС��0������ͷ������ڵ㡣
deleteAtIndex(index)��������� index ��Ч����ɾ�������еĵ� index ���ڵ㡣

ʾ����
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //�����Ϊ1-> 2-> 3
linkedList.get(1);            //����2
linkedList.deleteAtIndex(1);  //����������1-> 3
linkedList.get(1);            //����3

��ʾ��
����valֵ���� [1, 1000] ֮�ڡ�
������������  [1, 1000] ֮�ڡ�
�벻Ҫʹ�����õ� LinkedList �⡣
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
*/

#include<iostream>
#include<algorithm>

using namespace std;

class MyLinkedList 
{
public:
    int val;
	MyLinkedList* next;
	MyLinkedList* prev;

public:
    /** Initialize your data structure here. */
    MyLinkedList() 
    {
        val = 0;
        next = NULL;
		prev = NULL;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) 
    {
        if (index < 0)
            return -1;
        MyLinkedList* temp = this->next;
        int res;
        for (int i = 0; i < index + 1; i++)
        {
            if (!temp)
                return -1;
            res = temp->val;
            temp = temp->next;
        }
        return res;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) 
    {
        MyLinkedList* newnode = new MyLinkedList();
        newnode->val = val;
        newnode->next = this->next;
		newnode->prev = NULL;
		if(newnode->next)
			newnode->next->prev = newnode;
        this->next = newnode;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) 
    {
        MyLinkedList* temp = this;
        MyLinkedList* newnode = new MyLinkedList();
        newnode->val = val;
		newnode->next = NULL;
        while (temp->next != NULL)
            temp = temp->next;
		newnode->prev = temp;
        temp->next = newnode;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) 
    {
        if (index <= 0)
        {
            this->addAtHead(val);
            return;
        }
        MyLinkedList* temp1 = this->next;
        MyLinkedList* temp2 = this->next;
        for (int i = 0; i < index; i++) 
        {
            if (!temp2)
            {
                if (i < index)
                    return;
            }
            else
            {
                temp1 = temp2;        //��ȡindex-1���ĵ�ַ
                temp2 = temp2->next;  //��ȡindex���ĵ�ַ
                if (!temp2)
                {
                    if (i+1 == index)
                    {
                        this->addAtTail(val);
                        return;
                    }
                }
            }
        }
        MyLinkedList* newnode = new MyLinkedList();
        newnode->val = val;
		newnode->next = temp2;
		newnode->prev = temp1;
        temp1->next = newnode;
		newnode->next->prev = newnode;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) 
    {
        if (index < 0)
            return;
        MyLinkedList* temp1 = this;
        MyLinkedList* temp2 = this->next;
        for (int i = 0; i < index; i++)
        {
            if (!temp2)
            {
                if (i <= index)
                    return;
            }
            else
            {
                temp1 = temp2;        //��ȡindex-1���ĵ�ַ
                temp2 = temp2->next;  //��ȡindex���ĵ�ַ
				if (!temp2)
				{
					if (i + 1 == index)
						return;
				}
            }
        }
		if (temp2->next)
			temp2->next->prev = temp1;
        temp1->next = temp2->next;
        delete temp2;
    }
};

