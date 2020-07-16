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
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int res = 0;
        int EndInterval = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < EndInterval)
            {
                res++;
            }
            else
            {
                EndInterval = intervals[i][1];
            }
        }
        return res;
    }
};