// LEETCODE -> Sudoku Solver
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int i, int j, char num, vector<vector<char>>& board)
    {
        for(int x = 0; x < 9; x++)
        {
            if(board[i][x] == num)
                return false;
        }
        for(int x = 0; x < 9; x++)
        {
            if(board[x][j] == num)
                return false;
        }
        for(int x = 0; x < 3; x++)
        {
            int row = (3*(i/3) + x);
            for(int y = 0; y < 3; y++)
            {
                int col = (3*(j/3) + y);
                if(board[row][col] == num)
                    return false;
            }
        }
        return true;
    }
    bool f(vector<vector<char>>& board, int i = 0, int j = 0)
    {
        if(i == 9)
            return true;
        if(board[i][j] == '.')
        {
            for(int x = 0; x < 9; x++)
            {
                char num = ('1' + x);
                if(isSafe(i, j, num, board))
                {
                    board[i][j] = num;
                    if(j == 8)
                    {
                        if(f(board, i + 1, 0))
                            return true;
                    }
                    else
                    {
                        if(f(board, i, j + 1))
                            return true;
                    }
                    board[i][j] = '.';
                }
            }
            return false;
        }
        else
        {
            if(j == 8)
                return f(board, i + 1, 0);
            return f(board, i, j +  1);
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        f(board);
    }
};