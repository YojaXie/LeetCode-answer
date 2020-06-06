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

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int nums = matrix[0].size();
        int nums_half = (nums + 1) / 2; 
        int temp = 0;
        for (int i = 0; i < nums_half; i++)    
        {
            for (int j = i; j < nums - 1 - i; j++) 
            {
                temp = matrix[j][nums -1 - i];
                matrix[j][nums - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;

                temp = matrix[nums - 1 - i][nums - 1 - j];
                matrix[nums - 1 - i][nums - 1 - j] = matrix[i][j];
                matrix[i][j] = temp;

                temp = matrix[nums - 1 - j][i];
                matrix[nums - 1 - j][i] = matrix[i][j];
                matrix[i][j] = temp;

            }
        }
    }
};
