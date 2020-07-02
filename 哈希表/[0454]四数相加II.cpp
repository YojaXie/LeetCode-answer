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
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
	{
		unordered_map<int, int> AplusB;
		int count = 0;
		for (int a : A)
		{
			for (int b : B)
			{
				int sum = a + b;
				if (AplusB.count(sum) > 0)
					AplusB[sum] += 1;
				else
					AplusB[sum] = 1;
			}
		}
		for (int c : C)
		{
			for (int d : D)
			{
				int sum = c + d;
				if (AplusB.count(-sum) > 0)
					count = count + AplusB[-sum];
			}
		}
		return count;
	}
};