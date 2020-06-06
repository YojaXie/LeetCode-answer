/*
��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� char[] ����ʽ������

��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣

����Լ��������е������ַ����� ASCII ����еĿɴ�ӡ�ַ���

ʾ�� 1��

���룺["h","e","l","l","o"]
�����["o","l","l","e","h"]
ʾ�� 2��

���룺["H","a","n","n","a","h"]
�����["h","a","n","n","a","H"]
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
	void reverseString(vector<char>& s) 
	{
		if (s.empty())
			return;
		vector<char>::iterator leftp = s.begin();
		vector<char>::iterator rightp = s.end()--;
		for (; leftp < rightp; rightp--, leftp++)
		{
			char temp;
			temp = *rightp;
			*rightp = *leftp;
			*leftp = temp;
		}
	}
};


int main()
{
	vector<char> vv;
	vv.push_back('s');
	vv.push_back('b');
	cout << *(vv.end()--) << endl;
}