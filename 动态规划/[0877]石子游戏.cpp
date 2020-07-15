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
    bool stoneGame(vector<int>& piles) 
    {
        vector<vector<pair<int, int>>> dp(piles.size(), vector<pair<int, int>>(piles.size(), { 0,0 }));
        for (int i = 0; i < piles.size(); i++)
        {
            dp[i][i].second = piles[i];
        }
        for (int i = piles.size() - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < piles.size(); j++)
            {
                if ((i + j) % 2 == 1)
                {
                    dp[i][j].first = max(piles[i] + dp[i + 1][j].first, piles[j] + dp[i][j - 1].first);
                    dp[i][j].second = min(dp[i + 1][j].second, dp[i][j - 1].second);
                }
                else
                {
                    dp[i][j].second = max(piles[i] + dp[i + 1][j].second, piles[j] + dp[i][j - 1].second);
                    dp[i][j].first = min(dp[i + 1][j].first, dp[i][j - 1].first);
                }
            }
        }
        return dp[0][piles.size() - 1].first > dp[0][piles.size() - 1].second ? true : false;
    }
};