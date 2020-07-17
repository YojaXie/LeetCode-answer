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
	vector<string> fizzBuzz(int n) {
		vector<string> res;
		for (int i = 1; i <= n; i++) {
			if (i % 15 == 0)
				res.push_back("FizzBuzz");
			else if (i % 5 == 0)
				res.push_back("Buzz");
			else if (i % 3 == 0)
				res.push_back("Fizz");
			else {
				int DigitsNum = log10(i);
				string Num;
				for (int j = DigitsNum; j >= 0; j--) {
					int temp = i / int(pow(10, j)) % 10 + '0';
					Num.push_back(temp);
				}
				res.push_back(Num);
			}
		}
		return res;
	}
};