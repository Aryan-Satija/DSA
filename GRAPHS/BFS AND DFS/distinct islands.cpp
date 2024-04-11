// CODING NINJAS -> DISTINCT ISLANDS
// SHIFTING OF ORIGIN
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> bfs(int** arr, int sr, int sc, int n, int m)
{
    queue<pair<int, int>> q;
    q.push({sr, sc}); arr[sr][sc] = 0;
    vector<pair<int, int>> island;
    while(!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        island.push_back({i - sr, j - sc});
        // right
        if(j + 1 < m and arr[i][j+1] == 1)
        {
            arr[i][j+1] = 0;
            q.push({i, j + 1});
        }    
        // up
        if(i - 1 >= 0 and arr[i-1][j] == 1) 
        {
            arr[i-1][j] = 0;
            q.push({i-1, j});
        }   
        // down
        if(i + 1 < n and arr[i+1][j] == 1) 
        {
            arr[i+1][j] = 0;
            q.push({i+1, j});
        }   
        // left
        if(j - 1 >= 0 and arr[i][j-1] == 1)
        {
            arr[i][j-1] = 0;
            q.push({i, j - 1});
        }    
    }
    return island;
}
int distinctIslands(int** arr, int n, int m)
{
    set<vector<pair<int, int>>> islands;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 1)
                islands.insert(bfs(arr, i, j, n, m));
        }
    }
    return islands.size();
}