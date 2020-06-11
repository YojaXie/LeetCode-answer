/*
����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� ��� pos �� -1�����ڸ�������û�л���
˵�����������޸ĸ���������

ʾ�� 1��
���룺head = [3,2,0,-4], pos = 1
�����tail connects to node index 1
���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣

ʾ�� 2��
���룺head = [1,2], pos = 0
�����tail connects to node index 0
���ͣ���������һ��������β�����ӵ���һ���ڵ㡣

ʾ�� 3��
���룺head = [1], pos = -1
�����no cycle
���ͣ�������û�л���
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode* detectCycle(ListNode* head) 
	{
		ListNode* slowP = head;
		ListNode* fastP = head;
		ListNode* firstpos = head;
		while (1)
		{
			if (fastP == NULL || fastP->next == NULL)
				return NULL;
			slowP = slowP->next;
			fastP = fastP->next->next;
			if (slowP == fastP)
				break;
		}
		while (slowP != firstpos)
		{
			slowP = slowP->next;
			firstpos = firstpos->next;
		}
		return firstpos;
	}
};
