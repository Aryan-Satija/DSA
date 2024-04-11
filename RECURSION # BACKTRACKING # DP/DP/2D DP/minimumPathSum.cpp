#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &DP)
    {
        if(row == 0 and col == 0)
            return grid[0][0];
        if(DP[row][col] != -1)
            return DP[row][col];
        int minSum = INT_MAX;
        // left sai aaya hoga
        if(col > 0)
            minSum = min(minSum, f(row, col - 1, grid, DP));
        // ya phir upar sai aaya hoga
        if(row > 0)
            minSum = min(minSum, f(row - 1, col, grid, DP));
        return DP[row][col] = (grid[row][col] + minSum);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> DP(n, vector<int>(m, -1));
        return f(n - 1, m - 1, grid, DP);
    }
};