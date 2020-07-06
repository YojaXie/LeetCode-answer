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
	vector<int> plusOne(vector<int>& digits) 
	{
		int carry = 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if(digits[i] == 9)
				digits[i] = 0;
			else
			{
				digits[i] += 1;
				break;
			}
			if (i == 0)
				digits.insert(digits.begin(), 1);
		}
		return digits;
	}
};