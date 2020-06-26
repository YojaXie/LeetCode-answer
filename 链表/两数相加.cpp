/*
�������� �ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ��� ���� �ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�
�����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ��

ʾ����
���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807
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