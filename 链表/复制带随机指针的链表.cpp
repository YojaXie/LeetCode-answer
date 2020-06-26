/*
����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
Ҫ�󷵻��������� �����
������һ���� n ���ڵ���ɵ���������ʾ����/����е�����ÿ���ڵ���һ�� [val, random_index] ��ʾ��
val��һ����ʾ Node.val ��������
random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n-1���������ָ���κνڵ㣬��Ϊ  null ��

ʾ�� 1��
���룺head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
�����[[7,null],[13,0],[11,4],[10,2],[1,0]]

ʾ�� 2��
���룺head = [[1,1],[2,1]]
�����[[1,1],[2,1]]

ʾ�� 3��
���룺head = [[3,null],[3,0],[3,null]]
�����[[3,null],[3,0],[3,null]]

ʾ�� 4��
���룺head = []
�����[]
���ͣ�����������Ϊ�գ���ָ�룩����˷��� null��

��ʾ��
-10000 <= Node.val <= 10000
Node.random Ϊ�գ�null����ָ�������еĽڵ㡣
�ڵ���Ŀ������ 1000 ��

˼·����ԭ����ÿ���ڵ�����һ����¡�ڵ㡣��random��ֵ���ٽ�ԭ������ѳ�����������˿���ѣ���
*/

#include<iostream>
#include<algorithm>

using namespace std;


// Definition for a Node.
class Node 
{
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution 
{
public:
    Node* copyRandomList(Node* head) 
    {
        if (!head)
            return NULL;
        Node* iterateP = head;
        Node* temp = head;
        while (iterateP)
        {
            temp = new Node(iterateP->val);
            temp->next = iterateP->next;
            iterateP->next = temp;
            iterateP = iterateP->next->next;
        }
        iterateP = head;
        while (iterateP)
        {
            if(iterateP->random)
                iterateP->next->random = iterateP->random->next;
            iterateP = iterateP->next->next;
        }
        iterateP = head;
        Node* res = head->next;
        Node* iterateNewP = head->next;
        while (iterateP)
        {
            iterateP->next = iterateNewP->next;
            iterateP = iterateP->next;
            if (!iterateP)
                break;
            iterateNewP->next = iterateP->next;
            iterateNewP = iterateNewP->next;
        }
        return res;
    }
};