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

class Solution 
{
public:
	int numIslands(vector<vector<char>>& grid) 
	{
		if (grid.size())
			return 0;
		int nums = grid.size() * grid[0].size();
		int res = 0;
		queue<char*> queueIslands;
		set<char*> used;
		for (vector<vector<char>>::iterator it = grid.begin(); it != grid.end(); it++)
		{
			for (int i = 0; i < (*it).size(); i++)
			{
				if (used.size() == nums)
					return res;
				int step = 0;
				int* root = NULL;
				queueIslands.push(&(*it)[i]);
				used.insert(&(*it)[i]);
				while (!queueIslands.empty())
				{
					step = step + 1;
					int size = queueIslands.size();
					for (int i = 0; i < size; i++)
					{
						if (queueIslands.front())
						{

							for (int j = 0; j < grid[step - 1].size(); j++)
							{

							}

						}
					}
				}
			}
		}
	}
};