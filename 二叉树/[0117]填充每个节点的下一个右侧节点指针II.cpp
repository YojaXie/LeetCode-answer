/*
����һ��������

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��
��ʼ״̬�£����� next ָ�붼������Ϊ NULL��

���ף�
��ֻ��ʹ�ó���������ռ䡣
ʹ�õݹ����Ҳ����Ҫ�󣬱����еݹ����ռ�õ�ջ�ռ䲻��������Ŀռ临�Ӷȡ�

ʾ����
���룺root = [1,2,3,4,5,null,7]
�����[1,#,2,3,#,4,5,7,#]

��ʾ��
���еĽڵ���С�� 6000
-100 <= node.val <= 100
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
        Node* CurrentStepHeadNode = NULL;
        if (root->left)  CurrentStepHeadNode = root->left;
        else CurrentStepHeadNode = root->right;
        Node* temp = root;
        while (CurrentStepHeadNode)
        {
            bool FoundHeadNode = false;
            Node* LastStepNode = temp;
            Node* CurrentStepNode = CurrentStepHeadNode;
            CurrentStepHeadNode = NULL;
            if (CurrentStepNode->left && !FoundHeadNode)
            {
                CurrentStepHeadNode = CurrentStepNode->left;
                temp = CurrentStepNode;
                FoundHeadNode = true;
            }
            if (CurrentStepNode->right && !FoundHeadNode)
            {
                CurrentStepHeadNode = CurrentStepNode->right;
                temp = CurrentStepNode;
                FoundHeadNode = true;
            }
            while (CurrentStepNode && LastStepNode)
            {
                if (LastStepNode->left && LastStepNode->right)
                {

                    if (LastStepNode->left != CurrentStepNode)
                    {
                        CurrentStepNode->next = LastStepNode->left;
                        if (CurrentStepNode->left && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->left;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                        if (CurrentStepNode->right && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->right;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                        CurrentStepNode = CurrentStepNode->next;
                    }

                    CurrentStepNode->next = LastStepNode->right;
                    if (CurrentStepNode->left && !FoundHeadNode)
                    {
                        CurrentStepHeadNode = CurrentStepNode->left;
                        temp = CurrentStepNode;
                        FoundHeadNode = true;
                    }
                    if (CurrentStepNode->right && !FoundHeadNode)
                    {
                        CurrentStepHeadNode = CurrentStepNode->right;
                        temp = CurrentStepNode;
                        FoundHeadNode = true;
                    }
                    CurrentStepNode = CurrentStepNode->next;
                    if (CurrentStepNode->left && !FoundHeadNode)
                    {
                        CurrentStepHeadNode = CurrentStepNode->left;
                        temp = CurrentStepNode;
                        FoundHeadNode = true;
                    }
                    if (CurrentStepNode->right && !FoundHeadNode)
                    {
                        CurrentStepHeadNode = CurrentStepNode->right;
                        temp = CurrentStepNode;
                        FoundHeadNode = true;
                    }
                    LastStepNode = LastStepNode->next;
                }
                else if(LastStepNode->left && !LastStepNode->right)
                {
                    if (LastStepNode->left != CurrentStepNode)
                    {
                        CurrentStepNode->next = LastStepNode->left;
                        if (CurrentStepNode->left && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->left;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                        if (CurrentStepNode->right && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->right;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                        CurrentStepNode = CurrentStepNode->next;
                        if (CurrentStepNode->left && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->left;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                        if (CurrentStepNode->right && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->right;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                    }
                    LastStepNode = LastStepNode->next;
                }
                else if (!LastStepNode->left && LastStepNode->right)
                {
                    if (LastStepNode->right != CurrentStepNode)
                    {
                        CurrentStepNode->next = LastStepNode->right;
                        if (CurrentStepNode->left && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->left;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                        if (CurrentStepNode->right && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->right;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                        CurrentStepNode = CurrentStepNode->next;
                        if (CurrentStepNode->left && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->left;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                        if (CurrentStepNode->right && !FoundHeadNode)
                        {
                            CurrentStepHeadNode = CurrentStepNode->right;
                            temp = CurrentStepNode;
                            FoundHeadNode = true;
                        }
                    }
                    LastStepNode = LastStepNode->next;
                }
                else
                {
                    LastStepNode = LastStepNode->next;
                }
            }
        }
        return root;
    }
};