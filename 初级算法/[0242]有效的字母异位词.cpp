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
	bool isAnagram(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		if (s == t) return true;
		else return false;
	}
};