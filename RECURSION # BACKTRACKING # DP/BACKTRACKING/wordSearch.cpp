#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool f(int i, int j, int r, int c, vector<vector<char>>& board, string word){
        if(board[i][j] != word[0])
            return false;
        if(word.length() == 1)
            return true;
        char original = board[i][j];
        board[i][j] = '#';
        // up
        if(i - 1 >= 0 && board[i-1][j] != '#'){
            if(f(i - 1, j, r, c, board, word.substr(1))){
                board[i][j] = original;
                return true;
            }
        }
        // down
        if(i + 1 < r &&  board[i+1][j] != '#'){
            if(f(i + 1, j, r, c, board, word.substr(1))){
                board[i][j] = original;
                return true;
            }
        }
        // left
        if(j - 1 >= 0 && board[i][j-1] != '#'){
            if(f(i, j - 1, r, c, board, word.substr(1))){
                board[i][j] = original;
                return true;
            }
        }
        // right
        if(j + 1 < c &&  board[i][j+1] != '#'){
            if(f(i, j + 1, r, c, board, word.substr(1))){
                board[i][j] = original;
                return true;
            }
        }
        board[i][j] = original;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size(), c = board[0].size();
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(f(i, j, r, c, board, word))
                    return true;
            }
        }
        return false; 
    }
};