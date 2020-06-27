/*
����һ��������������������Ҷ�ӽڵ㶼��ͬһ�㣬ÿ�����ڵ㶼�������ӽڵ㡣�������������£�

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��
��ʼ״̬�£����� next ָ�붼������Ϊ NULL��


��ʾ��
��ֻ��ʹ�ó���������ռ䡣
ʹ�õݹ����Ҳ����Ҫ�󣬱����еݹ����ռ�õ�ջ�ռ䲻��������Ŀռ临�Ӷȡ�
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

// Definition for a Node.
class Node 
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if (!root) return NULL;
        root->next = NULL;
        Node* CurrentStepHeadNode = root;
        while (CurrentStepHeadNode)
        {
            Node* LastStepNode = CurrentStepHeadNode;
            CurrentStepHeadNode = CurrentStepHeadNode->left;
            Node* CurrentStepNode = CurrentStepHeadNode;
            while (CurrentStepNode && LastStepNode)
            {
                CurrentStepNode->next = LastStepNode->right;
                CurrentStepNode = CurrentStepNode->next;
                LastStepNode = LastStepNode->next;
                if (LastStepNode)
                {
                    CurrentStepNode->next = LastStepNode->left;
                    CurrentStepNode = CurrentStepNode->next;
                }
            }
        }
        return root;
    }
};