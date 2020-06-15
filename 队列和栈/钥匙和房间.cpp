/*
�� N �����䣬��ʼʱ��λ�� 0 �ŷ��䡣ÿ�������в�ͬ�ĺ��룺0��1��2��...��N-1�����ҷ����������һЩԿ����ʹ�������һ�����䡣
����ʽ�ϣ�����ÿ������ i ����һ��Կ���б� rooms[i]��ÿ��Կ�� rooms[i][j] �� [0,1��...��N-1] �е�һ��������ʾ��
���� N = rooms.length�� Կ�� rooms[i][j] = v ���Դ򿪱��Ϊ v �ķ��䡣
������� 0 �ŷ�������������з��䶼����ס��
��������ɵ��ڷ���֮�������߶���
����ܽ���ÿ�����䷵�� true�����򷵻� false��

ʾ�� 1��
����: [[1],[2],[3],[]]
���: true
����:
���Ǵ� 0 �ŷ��俪ʼ���õ�Կ�� 1��
֮������ȥ 1 �ŷ��䣬�õ�Կ�� 2��
Ȼ������ȥ 2 �ŷ��䣬�õ�Կ�� 3��
�������ȥ�� 3 �ŷ��䡣
���������ܹ�����ÿ�����䣬���Ƿ��� true��

ʾ�� 2��
���룺[[1,3],[3,0,1],[2],[0]]
�����false
���ͣ����ǲ��ܽ��� 2 �ŷ��䡣

��ʾ��
1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
���з����е�Կ�������ܼƲ����� 3000��
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;

class Solution 
{
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) 
	{
		set<int> used;
		queue<int> buffer;
		int RoomNum = rooms.size();
		int root = 0;
		used.insert(0);
		buffer.push(0);
		while (!buffer.empty())
		{
			int cur = buffer.front();
			buffer.pop();
			for (int j = 0; j < rooms[cur].size(); j++)
			{
				if (used.count(rooms[cur][j]) == 0)
				{
					buffer.push(rooms[cur][j]);
					used.insert(rooms[cur][j]);
				}
			}
			if (used.size() == RoomNum) return true;
		}
		return false;
	}
};