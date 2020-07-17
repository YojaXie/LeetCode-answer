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
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> table;
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && table[s[i]] < table[s[i + 1]])
                res -= table[s[i]];
            else
                res += table[s[i]];
        }
        return res;
    }
};