/*
����һ���Ѱ����������� ���������飬�ҵ�������ʹ���������֮�͵���Ŀ������

����Ӧ�÷����������±�ֵ index1 �� index2������ index1 ����С�� index2��

˵��:

���ص��±�ֵ��index1 �� index2�����Ǵ��㿪ʼ�ġ�
����Լ���ÿ������ֻ��ӦΨһ�Ĵ𰸣������㲻�����ظ�ʹ����ͬ��Ԫ�ء�
ʾ��:

����: numbers = [2, 7, 11, 15], target = 9
���: [1,2]
����: 2 �� 7 ֮�͵���Ŀ���� 9 ����� index1 = 1, index2 = 2 ��
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int>& numbers, int target)
	{
		vector<int> res;
		int i = 0;
		int j = numbers.size() - 1;
		while (i < j)
		{
			if (numbers[j] + numbers[i] == target)
			{
				res.push_back(i + 1);
				res.push_back(j + 1);
				break;
			}
			else if (numbers[j] + numbers[i] < target)
				i++;
			else 
				j--;
		}
		return res;
	}
};