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
	int countPrimes(int n) {
		int res = 0;
		vector<bool> IsPrim(n, true);
		for (int i = 2; i < sqrt(n); i++) {
			if (IsPrim[i]) {
				for (int j = i * i; j < n; j += i) {
					IsPrim[j] = false;
				}
			}
		}
		for (int i = 2; i < n; i++)
			res += IsPrim[i];
		return res;
	}
};