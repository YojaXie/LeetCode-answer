/*
��һ���Զ�ά���������ʾ��ͼ����ÿһ��������ʾ��ͼ��������ֵ��С����ֵ�� 0 �� 65535 ֮�䡣
����һ������ (sr, sc) ��ʾͼ����Ⱦ��ʼ������ֵ���� ���У���һ���µ���ɫֵ newColor������������ɫ���ͼ��
Ϊ�������ɫ�������ӳ�ʼ���꿪ʼ����¼��ʼ��������������ĸ�����������ֵ���ʼ������ͬ���������ص㣬
�����ټ�¼���ĸ������Ϸ������������ص������Ƕ�Ӧ�ĸ�����������ֵ���ʼ������ͬ���������ص㣬�������ظ��ù��̡�
�������м�¼�����ص����ɫֵ��Ϊ�µ���ɫֵ��
��󷵻ؾ�����ɫ��Ⱦ���ͼ��

ʾ�� 1:
����:
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
���: [[2,2,2],[2,2,0],[2,0,1]]
����:
��ͼ������м䣬(����(sr,sc)=(1,1)),
��·�������з������������ص����ɫ�������ĳ�2��
ע�⣬���½ǵ�����û�и���Ϊ2��
��Ϊ�����������������ĸ����������ʼ�����������ص㡣

ע��:
image �� image[0] �ĳ����ڷ�Χ [1, 50] �ڡ�
�����ĳ�ʼ�㽫���� 0 <= sr < image.length �� 0 <= sc < image[0].length��
image[i][j] �� newColor ��ʾ����ɫֵ�ڷ�Χ [0, 65535]�ڡ�
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<set>

using namespace std;

class Solution 
{
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
	{
		int goalColor = image[sr][sc];
		set<pair<int, int>> used;
		DFS(image, sr, sc, newColor, goalColor, used);
		return image;

	}
	void DFS(vector<vector<int>>& image, int sr, int sc, int newColor, int goalColor, set<pair<int, int>> used)
	{
		if (image[sr][sc] == goalColor && used.count({ sr,sc })== 0)
		{
			used.insert({ sr, sc });
			image[sr][sc] = newColor;
			if (sr - 1 >= 0) DFS(image, sr - 1, sc, newColor, goalColor, used);
			if (sr + 1 < image.size()) DFS(image, sr + 1, sc, newColor, goalColor, used);
			if (sc - 1 >= 0) DFS(image, sr, sc - 1, newColor, goalColor, used);
			if (sc + 1 < image[0].size()) DFS(image, sr, sc + 1, newColor, goalColor, used);
		}
	}
};