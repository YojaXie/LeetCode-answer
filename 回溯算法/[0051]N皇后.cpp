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
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<string> board(n, string(n, '.'));
        backTrack(board, 0);
        return res;
    }
    void backTrack(vector<string>& board, int row)
    {
        if (row >= board.size())
        {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board[row].size(); col++)
        {
            if (!isValid(board, row, col))
                continue;
            board[row][col] = 'Q';
            backTrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string>& board, int row, int col)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < board[i].size(); i--, j++)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};