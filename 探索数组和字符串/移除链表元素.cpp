/*
ɾ�������е��ڸ���ֵ val �����нڵ㡣

ʾ��:
����: 1->2->6->3->4->5->6, val = 6
���: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) 
    {
        if (!head)
            return NULL;
        ListNode* iterateP = head;
        while (iterateP->next)
        {
            if (iterateP->next->val == val)
                iterateP->next = iterateP->next->next;
            else
                iterateP = iterateP->next;
        }
        if (head->val == val)
            head = head->next;
        return head;
    }
};