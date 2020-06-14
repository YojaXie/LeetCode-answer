/*
����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�������ֱ���������ڵ�½�������γɡ�
���⣬����Լ��������������߾���ˮ��Χ��

ʾ�� 1:
����:
11110
11010
11000
00000
���: 1

ʾ�� 2:
����:
11000
11000
00100
00011
���: 3

����: ÿ������ֻ����ˮƽ��/����ֱ���������ڵ�½�����Ӷ��ɡ�
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>

using namespace std;

// �õ�BFS (������ȱ�����
class Solution1
{
public:
	int numIslands(vector<vector<char>>& grid) 
	{
		if (grid.empty())
			return 0;
		int nums = grid.size() * grid[0].size();
		int res = 0;
		queue<pair<int, int>> queueIslands;
		set<pair<int, int>> used;
		int nr = grid.size();
		int nc = grid[0].size();
		for (int i = 0; i < nr; i++)
		{
			for (int j = 0; j < nc; j++)
			{
				if (used.size() == nums)
					return res;
				pair<int, int> root(i, j);
				if (used.count(root))
					continue;
				used.insert(root);
				if (grid[root.first][root.second]=='1')
					res = res + 1;
				else
					continue;
				queueIslands.push(root);
				while (!queueIslands.empty())
				{
					int row = queueIslands.front().first, col = queueIslands.front().second;
					queueIslands.pop();
					if (grid[row][col]=='1')
					{
						if (row - 1 >= 0 && used.count({ row - 1,col }) == 0)
						{
							queueIslands.push({ row - 1,col });
							used.insert({ row - 1,col });
						}
						if (row + 1 < nr && used.count({ row + 1,col }) == 0)
						{
							queueIslands.push({ row + 1,col });
							used.insert({ row + 1,col });
						}
						if (col - 1 >= 0 && used.count({ row,col - 1 }) == 0)
						{
							queueIslands.push({ row,col - 1 });
							used.insert({ row,col - 1 });
						}
						if (col + 1 < nc && used.count({ row,col + 1 }) == 0)
						{
							queueIslands.push({ row,col + 1 });
							used.insert({ row,col + 1 });
						}
					}
				}
			}
		}
		return res;
	}
};

//�õ�DFS��������ȱ���
class Solution2
{
public:
	int numIslands(vector<vector<char>>& grid) 
	{
		int res = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[0].size(); j++)
			{
				if (grid[i][j] == '1')
				{
					res = res + 1;
					DFS(i, j, grid);
				}
			}
		}
		return res;
	}
	void DFS(int i, int j, vector<vector<char>>& grid)
	{
		if (grid[i][j] == '1')
		{
			grid[i][j] = 0;
			if (i - 1 >= 0)  DFS(i - 1, j, grid);
			if (i + 1 < grid.size())  DFS(i + 1, j, grid);
			if (j - 1 >= 0)  DFS(i, j - 1, grid);
			if (j + 1 < grid[0].size())  DFS(i, j + 1, grid);
		}
		return;
	}
};