#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>
#include<map>

using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		if (n == 0) return "";
		if (n == 1) return "1";
		return TopDown(2, n, "1");
	}
	string TopDown(int i, int n, string Last)
	{
		if (i > n)
		{
			return Last;
		}
		string Current;
		for (int k = 0; k < Last.size(); )
		{
			char CurrentChar = Last[k];
			int count = 0;
			while (k < Last.size() && CurrentChar == Last[k])
			{
				count++;
				k++;
			}
			for (int j = int(log10(count)); j >= 0; j--)
			{
				char chr = (count / int(pow(10, j))) % 10 + '0';
				Current.push_back(chr);
			}
			Current.push_back(CurrentChar);
		}
		return TopDown(i + 1, n, Current);
	}
};