/*
����һ��������ת����������ÿ���ڵ������ƶ� k ��λ�ã����� k �ǷǸ�����

ʾ�� 1:
����: 1->2->3->4->5->NULL, k = 2
���: 4->5->1->2->3->NULL

����:
������ת 1 ��: 5->1->2->3->4->NULL
������ת 2 ��: 4->5->1->2->3->NULL

ʾ�� 2:
����: 0->1->2->NULL, k = 4
���: 2->0->1->NULL

����:
������ת 1 ��: 2->0->1->NULL
������ת 2 ��: 1->2->0->NULL
������ת 3 ��: 0->1->2->NULL
������ת 4 ��: 2->0->1->NULL
*/

#include<iostream>
#include<algorithm>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode* rotateRight(ListNode* head, int k) 
	{
		if (!head)
			return NULL;
		ListNode* iterateP = head;
		ListNode* temp = head;
		int LenList = 0;
		while (iterateP)
		{
			LenList++;
			temp = iterateP;
			iterateP = iterateP->next;
		}
		if (k == 0 || k % LenList == 0)
			return head;
		iterateP = head;
		k = LenList - k % LenList;
		while (--k)
			iterateP = iterateP->next;
		temp->next = head;
		head = iterateP->next;
		iterateP->next = NULL;
		return head;
	}
};