/*
����һ���� 0 �� 1 ��ɵľ����ҳ�ÿ��Ԫ�ص������ 0 �ľ��롣
��������Ԫ�ؼ�ľ���Ϊ 1 ��

ʾ�� 1:
����:
0 0 0
0 1 0
0 0 0
���:
0 0 0
0 1 0
0 0 0

ʾ�� 2:
����:
0 0 0
0 1 0
1 1 1
���:
0 0 0
0 1 0
1 2 1

ע��:
���������Ԫ�ظ��������� 10000��
����������������һ��Ԫ���� 0��
�����е�Ԫ��ֻ���ĸ�����������: �ϡ��¡����ҡ�
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
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
	{
		set<pair<int, int>> used;
		vector<vector<int>> res(matrix);
		queue<pair<int, int>> buffer;
		for (int r = 0; r < matrix.size(); r++)
		{
			for (int c = 0; c < matrix[0].size(); c++)
			{
				pair<int, int> root = { r,c };
				used.insert(root);
				buffer.push(root);
				int step = -1;
				while (!buffer.empty())
				{
					step = step + 1;
					int size = buffer.size();
					for (int i = 0; i < size; i++)
					{
						int sr = buffer.front().first;
						int sc = buffer.front().second;
						buffer.pop();
						if (matrix[sr][sc] == 0)
						{
							res[r][c] = step;
							buffer = queue<pair<int, int>>();
							break;
						}
						else
						{
							if (sr - 1 >= 0 && used.count({ sr - 1, sc }) == 0) { buffer.push({ sr - 1, sc }); used.insert({ sr - 1, sc }); }
							if (sr + 1 < matrix.size() && used.count({ sr + 1, sc }) == 0) { buffer.push({ sr + 1, sc }); used.insert({ sr + 1, sc }); }
							if (sc - 1 >= 0 && used.count({ sr, sc - 1 }) == 0) { buffer.push({ sr, sc - 1 }); used.insert({ sr, sc - 1 }); }
							if (sc + 1 < matrix[0].size() && used.count({ sr, sc + 1 }) == 0) { buffer.push({ sr, sc + 1 }); used.insert({ sr, sc + 1 }); }
						}
					}
				}
				used.clear();
			}
		}
		return res;
	}
};