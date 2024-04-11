// LEETCODE -> Number of Islands
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void DFS(int x, int y, vector<vector<char>>& grid, vector<vector<bool>> &isVis)
    {
        if(grid[y][x] == '0')
            return;
        isVis[y][x] = true;
        // right
        if((x + 1) < grid[0].size() and !isVis[y][x + 1])
            DFS(x + 1, y, grid, isVis);
        // left
        if((x - 1) >= 0 and !isVis[y][x - 1])
            DFS(x - 1, y, grid, isVis);
        // down
        if((y + 1) < grid.size() and !isVis[y + 1][x])
            DFS(x, y + 1, grid, isVis);
        // up
        if((y - 1) >= 0 and !isVis[y - 1][x])
            DFS(x, y - 1, grid, isVis);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> isVis(grid.size(), vector<bool>(grid[0].size(), false));
        int island = 0 ;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                // land
                if(grid[i][j] == '1' and !isVis[i][j])
                {
                    DFS(j, i, grid, isVis);
                    island++;
                }
            }
        }
        return island;
    }
};