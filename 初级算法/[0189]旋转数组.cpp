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
	void rotate(vector<int>& nums, int k) 
	{
		if (nums.empty()) return;
		int reference = 0, i = 0;
		int buffer = 0;
		int size = nums.size();
		int commen = min(size, k);
		for (; commen > 0; commen--)
		{
			if (size % commen == 0 && k % commen == 0) break;
		}
		while (1)
		{
			buffer = nums[(i + k) % size];
			nums[(i + k) % size] = nums[reference];
			nums[reference] = buffer;
			i = (i + k) % size;
			if (i == reference)
			{
				if (commen > 1)
				{
					reference++;
					i = reference;
					if (reference >= commen) return;
				}
				else return;
			}
		}
	}
};