/*
反转一个单链表。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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

// 方法一： 利用迭代反转
class Solution1 
{
public:
    ListNode* reverseList(ListNode* head) 
	{
		if (!head)
			return head;
		ListNode* temp;
		ListNode* iterateP = head;
		while (iterateP->next)
		{
			temp = iterateP->next;
			iterateP->next = iterateP->next->next;
			temp->next = head;
			head = temp;

		}
		return head;
    }
};

// 方法二： 利用递归反转
class Solution2
{
public:
	ListNode* reverseList(ListNode* head)
	{
		if (!head)
			return head;
		ListNode* iterateP = head;
		return diedai(head, iterateP);
	}
	ListNode* diedai(ListNode* head, ListNode* iterateP)
	{
		if (iterateP->next == NULL)
			return head;
		ListNode* temp;
		temp = iterateP->next;
		iterateP->next = iterateP->next->next;
		temp->next = head;
		head = temp;
		return diedai(head, iterateP);
	}
};