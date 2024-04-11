// LEETCODE -> NQUEENS2
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int c, int n, vector<bool> &row, vector<bool> &d1, vector<bool> &d2){
        if(c == n)  return 1;
        int cnt = 0;
        for(int r = 0; r < n; r++){
            if(row[r] and d1[r - c + n] and d2[r + c]){
                row[r] = false; d1[r - c + n] = false; d2[r + c] = false;
                cnt += f(c + 1, n, row, d1, d2);
                row[r] = true; d1[r - c + n] = true; d2[r + c] = true;
            }
        }
        return cnt;
    }
    int totalNQueens(int n) {
        vector<bool> row(n, true), d1(2*n + 1, true), d2(2*n + 1, true);
        return f(0, n, row, d1, d2);
    }
};