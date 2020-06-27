/*
给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

进阶：
你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

示例：
输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]

提示：
树中的节点数小于 6000
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