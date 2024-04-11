// LEETCODE -> Rotting Oranges
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // MULTI SOURCE BFS
        int fresh = 0;
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }
        if(fresh == 0)
            return 0;
        int time = -1;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int row = q.front().first; 
                int col = q.front().second;
                q.pop();
                // up 
                if((row - 1) >= 0 and grid[row - 1][col] == 1)
                {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                    fresh--;
                }
                // down
                if((row + 1) < grid.size() and grid[row + 1][col] == 1)
                {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                    fresh--;
                }
                // left
                if((col - 1) >= 0 and grid[row][col - 1] == 1)
                {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                    fresh--;
                }
                // right
                if((col + 1) < grid[0].size() and grid[row][col + 1] == 1)
                {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                    fresh--;
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};