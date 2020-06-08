/*
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�
�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodes Ϊ�ڵ�������

ʾ�� 1:
����: 1->2->3->4->5->NULL
���: 1->3->5->2->4->NULL

ʾ�� 2:
����: 2->1->3->5->6->4->7->NULL
���: 2->3->6->7->1->5->4->NULL

˵��:
Ӧ�����������ڵ��ż���ڵ�����˳��
����ĵ�һ���ڵ���Ϊ�����ڵ㣬�ڶ����ڵ���Ϊż���ڵ㣬�Դ����ơ�
*/



#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode* oddEvenList(ListNode* head) 
    {
        if (!head)
            return NULL;
        int i = 2;
        ListNode* oddP = head;
        ListNode* evenP = head->next;
        ListNode* iterate = head;
        while (iterate->next)
        {
            if (i % 2 == 0)
                iterate = iterate->next;
            else
            {
                oddP->next = iterate->next;
                iterate->next = iterate->next->next;
                oddP = oddP->next;
            }
            i++;
        }
        oddP->next = evenP;
        return head;
    }
};