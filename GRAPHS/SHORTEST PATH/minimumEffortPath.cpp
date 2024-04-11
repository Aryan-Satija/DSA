// LEETCODE -> Path With Minimum Effort
// dfs method
#include <bits/stdc++.h>
using namespace std;
int f(int r, int c, int n, int m, vector<vector<int>>& heights, vector<vector<bool>> isVis){
    if(r == (n-1) and c == (m-1)) return 0;
    isVis[r][c] = true;
    int minEffort = 1e9;
    // right
    if(c+1 < m and !isVis[r][c+1])
        minEffort =  min(minEffort, max(abs(heights[r][c] - heights[r][c+1]), f(r, c+1, n, m, heights, isVis)));
    // down
    if(r+1 < n and !isVis[r+1][c])
        minEffort = min(minEffort, max(abs(heights[r][c] - heights[r+1][c]), f(r+1, c, n, m, heights, isVis)));
    // left 
    if(c-1 >= 0 and !isVis[r][c-1])
        minEffort = min(minEffort, max(abs(heights[r][c] - heights[r][c-1]), f(r, c-1, n, m, heights, isVis)));
    // up
    if(r-1 >= 0 and !isVis[r-1][c])
        minEffort = min(minEffort, max(abs(heights[r][c] - heights[r-1][c]), f(r-1, c, n, m, heights, isVis)));
    return minEffort;
}
int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    vector<vector<bool>> isVis(n, vector<bool>(m, false));
    return f(0, 0, n, m, heights, isVis);
}
// using an algo similar to dijkstra's
int minimumEffortPath2(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({0, 0, 0}); effort[0][0] = 0;
    while(!pq.empty()){
        auto temp = pq.top(); pq.pop();
        int eff = temp[0], r = temp[1], c = temp[2];
        // down
        if(r + 1 < n and effort[r+1][c] > max(eff, abs(heights[r+1][c] - heights[r][c]))){
            effort[r+1][c] = max(eff, abs(heights[r+1][c] - heights[r][c]));
            pq.push({effort[r+1][c], r+1, c});
        }
        // up
        if(r - 1 >= 0 and effort[r-1][c] > max(eff, abs(heights[r-1][c] - heights[r][c]))){
            effort[r-1][c] = max(eff, abs(heights[r-1][c] - heights[r][c]));
            pq.push({effort[r-1][c], r-1, c});
        }
        // left
        if(c - 1 >= 0 and effort[r][c-1] > max(eff, abs(heights[r][c-1] - heights[r][c]))){
            effort[r][c-1] = max(eff, abs(heights[r][c-1] - heights[r][c]));
            pq.push({effort[r][c-1], r, c-1});
        }
        // right
        if(c + 1 < m and effort[r][c+1] > max(eff, abs(heights[r][c+1] - heights[r][c]))){
            effort[r][c+1] = max(eff, abs(heights[r][c+1] - heights[r][c]));
            pq.push({effort[r][c+1], r, c+1});
        }
    }
    return effort[n-1][m-1];
}