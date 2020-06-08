/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：
给定一个链表: 1->2->3->4->5, 和 n = 2.
当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：
给定的 n 保证是有效的。

进阶：
你能尝试使用一趟扫描实现吗？
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