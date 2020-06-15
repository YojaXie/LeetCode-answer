/*
�������� ��ͨ ͼ��һ���ڵ�����ã����㷵�ظ�ͼ�� �������¡����
ͼ�е�ÿ���ڵ㶼��������ֵ val��int�� �����ھӵ��б�list[Node]����
class Node {
    public int val;
    public List<Node> neighbors;
}
����������ʽ��
�������ÿ���ڵ��ֵ��������������ͬ�����磬��һ���ڵ�ֵΪ 1��val = 1�����ڶ����ڵ�ֵΪ 2��val = 2�����Դ����ơ���ͼ�ڲ���������ʹ���ڽ��б��ʾ��
�ڽ��б� �����ڱ�ʾ����ͼ�������б�ļ��ϡ�ÿ���б�������ͼ�нڵ���ھӼ���
�����ڵ㽫ʼ����ͼ�еĵ�һ���ڵ㣨ֵΪ 1��������뽫 �����ڵ�Ŀ��� ��Ϊ�Կ�¡ͼ�����÷��ء�

ʾ�� 1��
���룺adjList = [[2,4],[1,3],[2,4],[1,3]]
�����[[2,4],[1,3],[2,4],[1,3]]
���ͣ�
ͼ���� 4 ���ڵ㡣
�ڵ� 1 ��ֵ�� 1�����������ھӣ��ڵ� 2 �� 4 ��
�ڵ� 2 ��ֵ�� 2�����������ھӣ��ڵ� 1 �� 3 ��
�ڵ� 3 ��ֵ�� 3�����������ھӣ��ڵ� 2 �� 4 ��
�ڵ� 4 ��ֵ�� 4�����������ھӣ��ڵ� 1 �� 3 ��

ʾ�� 2��
���룺adjList = [[]]
�����[[]]
���ͣ��������һ�����б���ͼ����ֻ��һ��ֵΪ 1 �Ľڵ㣬��û���κ��ھӡ�

ʾ�� 3��
���룺adjList = []
�����[]
���ͣ����ͼ�ǿյģ��������κνڵ㡣

ʾ�� 4��
���룺adjList = [[2],[1]]
�����[[2],[1]]

��ʾ��
�ڵ��������� 100 ��
ÿ���ڵ�ֵ Node.val ����Ψһ�ģ�1 <= Node.val <= 100��
����ͼ��һ����ͼ������ζ��ͼ��û���ظ��ıߣ�Ҳû���Ի���
����ͼ������ģ�����ڵ� p �ǽڵ� q ���ھӣ���ô�ڵ� q Ҳ�����ǽڵ� p ���ھӡ�
ͼ����ͨͼ������ԴӸ����ڵ���ʵ����нڵ㡣
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution 
{
public:
    Node* cloneGraph(Node* node) 
    {
        if (!node) return NULL;
        map<Node*, Node*> used;
        Node* res = new Node(*node);
        used.insert(pair<Node*, Node*>(node, res));
        DFS(node, used, res);
        return res;
    }

    void DFS(Node* node, map<Node*, Node*>& used, Node* newnode)
    {
        for (int i=0;i<node->neighbors.size();i++)
        {
            if (used.count(node->neighbors[i]) == 0)
            {
                newnode->neighbors[i] = new Node(*(node->neighbors[i]));
                used.insert(pair<Node*, Node*>(node->neighbors[i], newnode->neighbors[i]));
                DFS(node->neighbors[i], used, newnode->neighbors[i]);
            }
            newnode->neighbors[i] = used[node->neighbors[i]];
        }
        return;
    }
};
