/*
����һ���� N �� N �����ʾ��ͼ������ÿ�����صĴ�СΪ 4 �ֽڡ��������һ���㷨����ͼ����ת 90 �ȡ�

��ռ�ö����ڴ�ռ��ܷ�������

ʾ�� 1:

���� matrix =
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

ԭ����ת�������ʹ���Ϊ:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
ʾ�� 2:

���� matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
],

ԭ����ת�������ʹ���Ϊ:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/



#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
	void rotate(vector<vector<int>>& matrix) 
	{
		int* p = &matrix[0][0];
		cout << (*p+2);
	}
};



int main()
{
	vector<vector<int>> matrix;
	vector<int> x1;
	x1.push_back(1);
	x1.push_back(2);
	x1.push_back(3);
	vector<int> x2;
	x2.push_back(4);
	x2.push_back(5);
	x2.push_back(6);
	vector<int> x3;
	x3.push_back(7);
	x3.push_back(8);
	x3.push_back(9);
	matrix.push_back(x1);
	matrix.push_back(x2);
	matrix.push_back(x3);
	Solution().rotate(matrix);
	return 0;
}