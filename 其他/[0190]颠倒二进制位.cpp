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
    uint32_t reverseBits(uint32_t n) {
        for (int i = 31; i >= 16; i--) {
            int HighBit = (n >> i) % 2;
            int LowBit = (n >> (31 - i)) % 2;
            n = n - (HighBit << i) + (HighBit << (31 - i));
            n = n - (LowBit << (31 - i)) + (LowBit << i);
        }
        return n;
    }
};