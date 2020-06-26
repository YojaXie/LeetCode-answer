/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode* iteratel1 = l1;
		ListNode* iteratel2 = l2;
		ListNode* newlist = NULL;
		ListNode* newhead = NULL;
		ListNode* newnode = NULL;

		int sum = 0;
		while (iteratel1 || iteratel2)
		{
			if (iteratel1 && iteratel2)
			{
				sum += iteratel1->val + iteratel2->val;
				newnode = new ListNode(sum % 10);
				sum = sum / 10;
				if (newlist)
					newlist->next = newnode;
				else
					newhead = newnode;
				newlist = newnode;
				iteratel1 = iteratel1->next;
				iteratel2 = iteratel2->next;
			}
			else if (!iteratel1 && iteratel2)
			{
				sum += iteratel2->val;
				newnode = new ListNode(sum % 10);
				sum = sum / 10;
				newlist->next = newnode;
				newlist = newnode;
				iteratel2 = iteratel2->next;
			}
			else
			{
				sum += iteratel1->val;
				newnode = new ListNode(sum % 10);
				sum = sum / 10;
				newlist->next = newnode;
				newlist = newnode;
				iteratel1 = iteratel1->next;
			}
		}
		if (sum)
		{
			newnode = new ListNode(sum);
			newlist->next = newnode;
		}
		return newhead;
	}
};