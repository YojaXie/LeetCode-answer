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
#include<ctime>

using namespace std;

class Solution
{
public:
	int kthGrammar(int N, int K)
	{
		return tail_recursion(K - 1);
	}
	int tail_recursion(int k)
	{
		if (k == 0) return 0;
		if (k % 2 == 0)
			return tail_recursion(k / 2);
		else
			return !tail_recursion(k / 2);
	}
};