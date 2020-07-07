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
	int myAtoi(string str)
	{
		if (str.empty()) return 0;
		string num;
		int i = 0;
		string IntMax = "2147483647";
		string IntMin = "-2147483648";
		int res = 0;
		while (i < str.size())
		{
			if (str[i] == ' ') i++;
			else if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
			{
				if (str[i] == '+' || str[i] == '-')
				{
					num.push_back(str[i]);
					i++;
					if (i >= str.size()) return 0;
					if (i < str.size() && (str[i]<'0' || str[i]>'9')) return 0;
					while (i < str.size() && str[i] >= '0' && str[i] <= '9')
					{
						if (str[i] != '0')
						{
							while (i < str.size() && str[i] >= '0' && str[i] <= '9')
							{
								num.push_back(str[i]);
								i++;
							}
							break;
						}
						i++;
					}
					break;
				}
				else
				{
					while (i < str.size() && str[i] >= '0' && str[i] <= '9')
					{
						if (str[i] != '0')
						{
							while (i < str.size() && str[i] >= '0' && str[i] <= '9')
							{
								num.push_back(str[i]);
								i++;
							}
							break;
						}
						i++;
					}
					break;
				}
			}
			else return 0;
		}
		if (num.empty()) return 0;
		if (num[0] == '-')
		{
			if ((num.size() == IntMin.size() && num > IntMin) || num.size() > IntMin.size()) return INT_MIN;
			for (int j = 1; j < num.size(); j++)
			{
				res -= (num[j] - '0') * int(pow(10, num.size() - 1 - j));
			}
			return res;
		}
		else
		{
			if (num[0] == '+') num.erase(0, 1);
			if ((num.size() == IntMax.size() && num > IntMax) || num.size() > IntMax.size()) return INT_MAX;
			for (int j = 0; j < num.size(); j++)
			{
				res += (num[j] - '0') * int(pow(10, num.size() - 1 - j));
			}
			return res;
		}
		return 0;
	}
};