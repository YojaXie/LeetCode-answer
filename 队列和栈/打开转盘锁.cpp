/*
����һ�������ĸ�Բ�β��ֵ�ת������ÿ�����ֶ���10�����֣� '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' ��
ÿ�����ֿ���������ת������� '9' ��Ϊ  '0'��'0' ��Ϊ '9' ��ÿ����ת��ֻ����תһ�����ֵ�һλ���֡�
���ĳ�ʼ����Ϊ '0000' ��һ�������ĸ����ֵ����ֵ��ַ�����
�б� deadends ������һ���������֣�һ�����ֵ����ֺ��б�����κ�һ��Ԫ����ͬ����������ᱻ�����������޷��ٱ���ת��
�ַ��� target ������Խ��������֣�����Ҫ������С����ת���������������β��ܽ��������� -1��

ʾ�� 1:
���룺deadends = ["0201","0101","0102","1212","2002"], target = "0202"
�����6
���ͣ�
���ܵ��ƶ�����Ϊ "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"��
ע�� "0000" -> "0001" -> "0002" -> "0102" -> "0202" �����������ǲ��ܽ����ģ�
��Ϊ�������� "0102" ʱ������ͻᱻ������

ʾ�� 2:
����: deadends = ["8888"], target = "0009"
�����1
���ͣ�
�����һλ������תһ�μ��� "0000" -> "0009"��

ʾ�� 3:
����: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
�����-1
���ͣ�
�޷���ת��Ŀ�������Ҳ���������

ʾ�� 4:
����: deadends = ["0000"], target = "8888"
�����-1

��ʾ��
�����б� deadends �ĳ��ȷ�ΧΪ [1, 500]��
Ŀ������ target ������ deadends ֮�С�
ÿ�� deadends �� target �е��ַ��������ֻ��� 10,000 �����ܵ���� '0000' �� '9999' �в�����
*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
#include<string>

using namespace std;

class Solution 
{
public:
	int openLock(vector<string>& deadends, string target) 
	{
		set<string> used;
		queue<string> queueLock;
		int step = 0;
		string root = "0000";
		queueLock.push(root);
		used.insert(root);
		while (!queueLock.empty())
		{
			step = step + 1;
			int size = queueLock.size();
			for (int i = 0; i < size; i++)
			{
				string password = queueLock.front();
				if (password == target)
					return step - 1;
				bool indeadends = false;
				queueLock.pop();
				for (vector<string>::iterator it = deadends.begin(); it < deadends.end(); it++)
				{
					if (*it == password)
					{
						indeadends = true;
						break;
					}
				}
				if (!indeadends)
				{
					for (int j = 0; j < password.size(); j++)
					{
						string newpassword = password;
						if (newpassword[j] == '9')
							newpassword[j] = '0';
						else
							newpassword[j] = newpassword[j] + 1;
						if (used.count(newpassword) == 0)
						{
							queueLock.push(newpassword);
							used.insert(newpassword);
						}

						newpassword = password;
						if (newpassword[j] == '0')
							newpassword[j] = '9';
						else
							newpassword[j] = newpassword[j] - 1;
						if (used.count(newpassword) == 0)
						{
							queueLock.push(newpassword);
							used.insert(newpassword);
						}
					}
				}

			}
		}
		return -1;
	}
};