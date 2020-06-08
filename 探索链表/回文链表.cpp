/*
请判断一个链表是否为回文链表。

示例 1:
输入: 1->2
输出: false

示例 2:
输入: 1->2->2->1
输出: true

进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/


#include<iostream>
#include<string>
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
	bool isPalindrome(ListNode* head) 
	{
		if (!head || !head->next)
			return true;
		int LenList = 1;
		ListNode* iterateP = head;
		ListNode* temp;
		while (iterateP->next)
		{
			LenList++;
			iterateP = iterateP->next;
		}
		iterateP = head;
		for (int i = 0; i < (LenList+1)/2 - 1; i++)
		{
			if (i == (LenList + 1) / 2 - 2 && LenList % 2 == 1)
				break;
			temp = iterateP->next;
			iterateP->next = iterateP->next->next;
			temp->next = head;
			head = temp;
		}
		if (LenList % 2 == 1)
			iterateP = iterateP->next->next;
		else
			iterateP = iterateP->next;
		for (int i = 0; i < LenList / 2; i++)
		{
			if (iterateP->val != head->val)
				return false;
			iterateP = iterateP->next;
			head = head->next;
		}
		return true;
	}
};