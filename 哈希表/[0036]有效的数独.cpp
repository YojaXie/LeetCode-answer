#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<unordered_set>

using namespace std;

class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_set<string> NumPos;
        for (int r = 0; r < board.size(); r++)
        {
            for (int c = 0; c < board[0].size(); c++)
            {
                if (board[r][c] == '.') continue;
                string NumR = string(1, board[r][c]).append("r"); NumR.push_back(r + '0');
                string NumC = string(1, board[r][c]).append("c"); NumC.push_back(c + '0');
                string NumM = string(1, board[r][c]).append("m"); NumM.push_back(c / 3 * 3 + r / 3 + '0');
                if (NumPos.count(NumR) == 1 || NumPos.count(NumC) == 1 || NumPos.count(NumM) == 1)
                    return false;
                else
                {
                    NumPos.insert(NumR);
                    NumPos.insert(NumC);
                    NumPos.insert(NumM);
                }
            }
        }
        return true;
    }
};