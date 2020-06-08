/*
��תһ��������

ʾ��:
����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL

����:
����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿
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

// ����һ�� ���õ�����ת
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

// �������� ���õݹ鷴ת
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