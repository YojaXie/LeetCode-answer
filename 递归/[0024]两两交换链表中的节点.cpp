#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<map>

using namespace std;


 // Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode* temp = head->next;
        head->next = head->next->next;
        temp->next = head;
        head = temp;
        if(head->next->next) 
            head->next->next = swapPairs(head->next->next);
        return head;
    }
};