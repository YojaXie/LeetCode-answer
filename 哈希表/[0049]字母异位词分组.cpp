#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        unordered_map<string, int> SortedStringSet;
        int channels = -1;
        for (string str : strs)
        {
            string SortedStr = str;
            sort(SortedStr.begin(), SortedStr.end());
            if (SortedStringSet.count(SortedStr) > 0)
            {
                res[SortedStringSet[SortedStr]].push_back(str);
            }
            else
            { 
                channels++;
                SortedStringSet.insert({ SortedStr,channels });
                vector<string> SameStr;
                SameStr.push_back(str);
                res.push_back(SameStr);
            }
        }
        return res;
    }
};