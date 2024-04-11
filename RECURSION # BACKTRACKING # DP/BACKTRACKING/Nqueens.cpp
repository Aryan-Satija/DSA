// LEETCODE -> N-QUEENS
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(int col, vector<string>&board, vector<vector<string>>&res,
    vector<int>left, vector<int>&Diagonal1, vector<int>&Diagonal2, int n){
        if(col == n){
            res.push_back(board);
            return;
        }
        for(int row = 0; row < n; row++){
           if(left[row]==0 && Diagonal1[row+col]==0 && Diagonal2[n - 1 + col - row]==0){
               board[row][col]='Q';
               left[row] = 1, Diagonal1[row + col] = 1, Diagonal2[n - 1 + col - row] = 1;
               f(col+1, board, res, left, Diagonal1, Diagonal2, n);
               board[row][col]='.';
               left[row] = 0, Diagonal1[row + col] = 0, Diagonal2[n - 1 + col - row] = 0;
           }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string>board(n);
        string s(n, '.');
        for(int i =0 ; i < n; i++) board[i]=s;
        vector<int> left(n, 0), Diagonal1(2*n-1, 0), Diagonal2(2*n-1, 0);
        f(0, board, res, left, Diagonal1, Diagonal2, n);
        return res;
    }
};