// LEETCODE -> Longest Increasing Path in a Matrix
#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, int r, int c, vector<vector<int>>& matrix, vector<vector<int>> &longestPaths){
    if(longestPaths[i][j] != -1)
        return longestPaths[i][j];
    int res = 1;
    // left
    if((j - 1) >= 0 and matrix[i][j-1] > matrix[i][j])
        res = max(res, 1 + f(i, j-1, r, c, matrix, longestPaths));
    // right
    if((j + 1) < c and matrix[i][j+1] > matrix[i][j])
        res = max(res, 1 + f(i, j+1, r, c, matrix, longestPaths));
    // up
    if((i - 1) >= 0 and matrix[i-1][j] > matrix[i][j])
        res = max(res, 1 + f(i-1, j, r, c, matrix, longestPaths));
    // down
    if((i + 1) < r and matrix[i+1][j] > matrix[i][j])
        res = max(res, 1 + f(i+1, j, r, c, matrix, longestPaths));
    return longestPaths[i][j] = res;
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int r = matrix.size(), c= matrix[0].size();
    vector<vector<int>> longestPaths(r, vector<int>(c, -1));
    int res = 1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            res = max(res, f(i, j, r, c, matrix, longestPaths));
        }
    }
    return res;
}