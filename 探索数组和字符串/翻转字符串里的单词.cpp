/*
����һ���ַ����������ת�ַ����е�ÿ�����ʡ�

ʾ�� 1��

����: "the sky is blue"
���: "blue is sky the"
ʾ�� 2��

����: "  hello world!  "
���: "world! hello"
����: �����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
ʾ�� 3��

����: "a good   example"
���: "example good a"
����: ����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����


˵����

�޿ո��ַ�����һ�����ʡ�
�����ַ���������ǰ����ߺ����������Ŀո񣬵��Ƿ�ת����ַ����ܰ�����
����������ʼ��ж���Ŀո񣬽���ת�󵥴ʼ�Ŀո���ٵ�ֻ��һ����
*/



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution 
{
public:
	string reverseWords(string s) 
	{
		if (s.empty())
			return s;
		string reverse_s = s;
		string temp=s;
		reverse(reverse_s.begin(), reverse_s.end());
		string ans=s;
		ans.clear();
		temp.clear();
		for (int i = 0; i < s.size(); i++)
		{
			if (temp.size() == 0 && reverse_s[i]==' ')
				continue;
			if (reverse_s[i] == ' ' ||  i==s.size()-1)
			{
				if(i == s.size() - 1 && reverse_s[i] != ' ')
					temp.push_back(reverse_s[i]);
				reverse(temp.begin(), temp.end());
				ans += temp + ' ';
				temp.clear();
				continue;
			}
			temp.push_back(reverse_s[i]);
		}
		if(!ans.empty())
			ans.pop_back();
		return ans;
	}
};

int main()
{
	string test = " 1";
	string ans;
	ans = Solution().reverseWords(test);
	cout << ans << endl;
}