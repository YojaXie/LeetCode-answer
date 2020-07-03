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
private:
	unordered_map<int, int> buffer;
public:
	int fib(int N) 
	{
		if (N == 1) return 1;
		if (N == 0) return 0;
		if (buffer.count(N) == 0)
			buffer[N] = fib(N - 1) + fib(N - 2);
		return buffer[N];
	}
};