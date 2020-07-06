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

// INT_MAX = 2147483647
// INT_MIN(-2147483647 - 1)
class Solution 
{
public:
	int reverse(int x) 
	{
		if (x == 0) return 0;
		string Int2String;
		string IntMax = "+2147483647";
		string IntMin = "-2147483648";
		if (x >= 0) Int2String.push_back('+');
		else Int2String.push_back('-');
		for (int i = 9; i >= 0; i--)
		{
			int NumBit = (x / int(pow(10, i))) % 10;
			if (NumBit != 0)
			{
				while (i >= 0)
				{
					NumBit = (x / int(pow(10, i))) % 10;
					NumBit >= 0 ? Int2String.push_back(NumBit + '0') : Int2String.push_back(-NumBit + '0');
					i--;
				}
			}
		}
		std::reverse(Int2String.begin() + 1, Int2String.end());
		if (Int2String[0] == '+' && Int2String.size() == IntMax.size())
		{
			if (Int2String > IntMax) return 0;
		}
		if (Int2String[0] == '-' && Int2String.size() == IntMin.size())
		{
			if (Int2String > IntMin) return 0;
		}

		int res = 0;
		for (int i = 1; i < Int2String.size(); i++)
		{
			if (Int2String[i] != '0')
			{
				while (i < Int2String.size())
				{
					res += int(Int2String[i] - '0') * pow(10, Int2String.size() - 1 - i);
					i++;
				}
			}
		}
		Int2String[0] == '+' ? res = res : res = -res;
		return res;
	}
};