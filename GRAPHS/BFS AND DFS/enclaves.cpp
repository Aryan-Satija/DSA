// LEETCODE ->  Number of Enclaves
#include <bits/stdc++.h>
using namespace std;
void dfs(int i, int j, vector<vector<int>>& board)
{
    board[i][j] = 0;
    // left
    if((j-1) >= 0 and board[i][j-1] == 1)
        dfs(i, j-1, board);
    // right 
    if((j+1) < board[0].size() and board[i][j+1] == 1)
        dfs(i, j+1, board);
    // down 
    if((i-1) >= 0 and board[i-1][j] == 1)
        dfs(i-1, j, board);
    // up
    if((i+1) < board.size() and board[i+1][j] == 1)
        dfs(i+1, j, board);
} 
int numEnclaves(vector<vector<int>> grid) {
    int r = grid.size(), c = grid[0].size();
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(i == 0 || j == 0 || i == (r - 1) || j == (c - 1))
            {
                if(grid[i][j] == 1)
                    dfs(i, j, grid);
            }
        }
    }
    int enclaves = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(grid[i][j] == 1)
                enclaves++;
        }
    }
    return enclaves;
}