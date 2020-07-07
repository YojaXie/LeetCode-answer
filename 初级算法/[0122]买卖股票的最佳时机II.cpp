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
	int maxProfit(vector<int>& prices)
	{
		int low = 0, high = 0;
		int profit = 0;
		while (low <= high && high < prices.size())
		{

			if (prices[low] <= prices[high])
			{
				profit += prices[high] - prices[low];
				low = high;
			}
			else
			{
				low = high;
			}
			high++;
			if (high == prices.size() && low < prices.size())
			{
				low++;
				high = low;
			}
		}
		return profit;
	}
};