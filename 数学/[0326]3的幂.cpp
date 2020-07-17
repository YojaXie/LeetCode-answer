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
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double temp = log(n) / log(3);
        int tempint = temp;
        tempint = temp - tempint > 0 ? tempint + 1 : tempint;
        return pow(3, int(tempint)) == double(n) ? true : false;
    }
};