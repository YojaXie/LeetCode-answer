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
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> OnePermute;
        backTrack(nums, OnePermute);
        return res;
    }
    void backTrack(vector<int>& nums, vector<int>& OnePermute)
    {
        if (OnePermute.size() == nums.size())
        {
            res.push_back(OnePermute);
            return;
        }
        for (int num : nums)
        {
            bool HasNum = false;
            for (int OneNum : OnePermute)
            {
                if (num == OneNum)
                    HasNum = true;
            }
            if (HasNum) continue;
            OnePermute.push_back(num);
            backTrack(nums, OnePermute);
            OnePermute.pop_back();
        }
    }
};