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
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        int res = 0;
        while (temp != 0) {
            res++;
            temp &= temp - 1;
        }
        return res;
    }
};