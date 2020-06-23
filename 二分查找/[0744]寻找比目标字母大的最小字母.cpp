/*
����һ���������ַ��б� letters ���б���ֻ����СдӢ����ĸ��
�����һ��Ŀ����ĸ target������Ѱ������һ�����б����Ŀ����ĸ�����С��ĸ��
�ڱȽ�ʱ����ĸ������ѭ�����ֵġ��ٸ����ӣ�
���Ŀ����ĸ target = 'z' �����ַ��б�Ϊ letters = ['a', 'b']����𰸷��� 'a'

ʾ����
����:
letters = ["c", "f", "j"]
target = "a"
���: "c"

����:
letters = ["c", "f", "j"]
target = "c"
���: "f"

����:
letters = ["c", "f", "j"]
target = "d"
���: "f"

����:
letters = ["c", "f", "j"]
target = "g"
���: "j"

����:
letters = ["c", "f", "j"]
target = "j"
���: "c"

����:
letters = ["c", "f", "j"]
target = "k"
���: "c"

��ʾ��
letters���ȷ�Χ��[2, 10000]�����ڡ�
letters ����Сд��ĸ��ɣ����ٰ���������ͬ����ĸ��
Ŀ����ĸtarget ��һ��Сд��ĸ��
*/

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) 
	{
		int leftp = 0, rightp = letters.size() - 1;
		while (leftp < rightp)
		{
			int midp = leftp + (1 + rightp - leftp) / 2;
			if (letters[midp] > target && letters[midp - 1] <= target) return letters[midp];
			else if (letters[midp - 1] > target) rightp = midp - 1;
			else leftp = midp;
		}
		if (rightp == letters.size() - 1 || leftp == 0) return letters[0];
		return '0';
	}
};