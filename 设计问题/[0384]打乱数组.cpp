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
private:
	vector<int> OriginalNum;
public:
	Solution(vector<int>& nums) {
		OriginalNum = nums;
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return OriginalNum;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> Nums = OriginalNum;
		for (int i = Nums.size(); i >= 1; i--) {
			int RandNum = rand() % i;
			swap(Nums[RandNum], Nums[i - 1]);
		}
		return Nums;
	}
};