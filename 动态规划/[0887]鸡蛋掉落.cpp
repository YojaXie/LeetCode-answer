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
    int superEggDrop(int K, int N) 
    {
        vector<int> dp1(N + 1, 0);
        for (int i = 0; i <= N; i++) dp1[i] = i;
        for (int k = 2; k <= K; k++)
        {
            vector<int> dp2(N + 1, 0);
            int x = 1;
            for (int i = 1; i <= N; i++)
            {
                while (x+1 <= i && max(dp1[x - 1], dp2[i - x]) >= max(dp1[x], dp2[i - x - 1])) x++;
                dp2[i] = 1 + max(dp1[x - 1], dp2[i - x]);
            }
            dp1 = dp2;
        }
        return dp1[N];
    }
};