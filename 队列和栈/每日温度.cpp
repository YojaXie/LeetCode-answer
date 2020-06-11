/*
请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。
例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
*/



#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<list>

using namespace std;

class Solution 
{
public:
	vector<int> dailyTemperatures(vector<int>& T) 
	{
		vector<int> res;
		res.resize(T.size());
		stack<int> buffer;
		vector<int> buffer_out;
		for (int i : T) buffer.push(i);
		for (int i = T.size()-1; i >=0; i--)
		{
			for (int j = buffer_out.size()-1; j >= 0; j--)
			{
				if (buffer.top() < buffer_out[j])
				{
					res[i] = buffer_out.size() - j;
					break;
				}
			}
			buffer_out.push_back(buffer.top());
			buffer.pop();
		}
		return res;
	}
};

int main()
{
	vector<int> T;
	T.push_back(73);
	T.push_back(74);
	T.push_back(75);
	T.push_back(71);
	T.push_back(69);
	T.push_back(72);
	T.push_back(76);
	T.push_back(73);
	vector<int> res = Solution().dailyTemperatures(T);

	return 0;
}