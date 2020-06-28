/*
ʵ��һ���������������������㽫ʹ�ö����������ĸ��ڵ��ʼ����������
���� next() �����ض����������е���һ����С������

ʾ����
BSTIterator iterator = new BSTIterator(root);
iterator.next();    // ���� 3
iterator.next();    // ���� 7
iterator.hasNext(); // ���� true
iterator.next();    // ���� 9
iterator.hasNext(); // ���� true
iterator.next();    // ���� 15
iterator.hasNext(); // ���� true
iterator.next();    // ���� 20
iterator.hasNext(); // ���� false

��ʾ��
next() �� hasNext() ������ʱ�临�Ӷ��� O(1)����ʹ�� O(h) �ڴ棬���� h �����ĸ߶ȡ�
����Լ��� next() ����������Ч�ģ�Ҳ����˵�������� next() ʱ��BST �����ٴ���һ����һ����С������
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator 
{
private:
	stack<TreeNode*> buffer;

public:
	BSTIterator(TreeNode* root) 
	{
		while (root)
		{
			buffer.push(root);
			root = root->left;
		}
	}

	/** @return the next smallest number */
	int next() 
	{
		TreeNode* root = buffer.top();
		buffer.pop();
		int res = root->val;
		root = root->right;
		while (root)
		{
			buffer.push(root);
			root = root->left;
		}
		return res;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() 
	{
		if (buffer.empty()) return false;
		else return true;
	}
};
