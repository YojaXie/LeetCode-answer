/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

#include<iostream>
#include<algorithm>

using namespace std;

/** Definition for singly-linked list. */
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution 
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 != NULL && l2 == NULL)
			return l1;
		if (l1 == NULL && l2 != NULL)
			return l2;
		ListNode* iterateP = l1;
		ListNode* head = l1;
		ListNode* l2left = l2;
		ListNode* l2right = l2;
		ListNode* temp = NULL;
		while (iterateP)
		{
			if (l2right->val >= iterateP->val)
			{
				temp = l2right;
				l2right = l2right->next;
				if (!l2right)
				{
					temp->next = iterateP->next;
					iterateP->next = l2left;
					return head;
				}
				if (!iterateP->next)
				{
					iterateP->next = l2left;
					return head;
				}
				if (l2right->val > iterateP->next->val)
				{
					temp->next = iterateP->next;
					iterateP->next = l2left;
					iterateP = temp->next;
					l2left = l2right;
				}
			}
			else
			{
				temp = l2right;
				l2right = l2right->next;
				if (!l2right)
				{
					temp->next = iterateP;
					head = l2left;
					return head;
				}
				if (l2right->val > iterateP->val)
				{
					temp->next = iterateP;
					head = l2left;
					l2left = l2right;
				}
			}
		}
	}
};