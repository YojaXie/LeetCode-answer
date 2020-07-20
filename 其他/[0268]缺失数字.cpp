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

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		long int res = 0;
		long int sum = 0;
		int size = nums.size() + 1;
		sum = nums.size() * size / 2;
		for (int num : nums)
			res += num;
		return sum - res;
	}

};