/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1:
输入:
11110
11010
11000
00000
输出: 1

示例 2:
输入:
11000
11000
00100
00011
输出: 3

解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
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