// LEETCODE -> Shortest Path in Binary Matrix
#include <bits/stdc++.h>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    // simple BFS would solve this problem
    int n = grid.size();
    if(grid[0][0] == 1 or grid[n-1][n-1] == 1) return -1;
    vector<vector<int>> directions = {
                                        {-1, -1}, {0, -1}, {1, -1},
                                        {-1,  0},          {1,  0},
                                        {-1,  1}, {0,  1}, {1,  1}
                                     };
    queue<vector<int>> q;
    grid[0][0] = 1;
    q.push({0, 0, 1});  // {row, col, distance from (0, 0)}
    while(!q.empty()){
        vector<int> tmp = q.front();
        q.pop();
        if(tmp[0] == (n-1) and tmp[1] == (n-1)) return tmp[2];
        for(int  i = 0; i < 8; i++){
            int ny = directions[i][0] + tmp[0], nx = directions[i][1] + tmp[1];
            if(ny >= 0 and ny < n and nx >= 0 and nx < n and grid[ny][nx] == 0){
                grid[ny][nx] = 1;
                q.push({ny, nx, 1+tmp[2]});
            }
        }
    }
    return -1;
}