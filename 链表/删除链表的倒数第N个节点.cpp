/*
����һ������ɾ������ĵ����� n ���ڵ㣬���ҷ��������ͷ��㡣

ʾ����
����һ������: 1->2->3->4->5, �� n = 2.
��ɾ���˵����ڶ����ڵ�������Ϊ 1->2->3->5.

˵����
������ n ��֤����Ч�ġ�

���ף�
���ܳ���ʹ��һ��ɨ��ʵ����
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
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode* fastP = head;
		ListNode* slowP = head;
		ListNode* temp;
		for (int i = 0; i < n; i++)
			fastP = fastP->next;
		if (fastP == NULL)
		{
			head = slowP->next;
			delete slowP;
			return head;
		}
		while (fastP->next)
		{
			fastP = fastP->next;
			slowP = slowP->next;
		}
		temp = slowP->next;
		slowP->next = slowP->next->next;
		delete temp;
		return head;
	}
};