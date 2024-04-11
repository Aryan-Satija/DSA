// LEETCODE -> Surrounded Regions
#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<char>>& board)
{
    board[i][j] = '*';
    // left
    if((j-1) >= 0 and board[i][j-1] == 'O')
        dfs(i, j-1, board);
    // right 
    if((j+1) < board[0].size() and board[i][j+1] == 'O')
        dfs(i, j+1, board);
    // down 
    if((i-1) >= 0 and board[i-1][j] == 'O')
        dfs(i-1, j, board);
    // up
    if((i+1) < board.size() and board[i+1][j] == 'O')
        dfs(i+1, j, board);
} 
void solve(vector<vector<char>>& board) {
    int r = board.size(), c = board[0].size();
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(i == 0 or j == 0 or i == (r - 1) or j == (c - 1))
            {
                if(board[i][j] == 'O')
                    dfs(i, j, board);
            }
        }
    }
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] == '*')
                board[i][j] = 'O';
            else if(board[i][j] == 'O')
                board[i][j] = 'X';
        }
    }
}