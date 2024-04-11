// LEETCODE -> 01 matrix
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<int, int>> q;
    for(int i = 0; i < mat.size(); i++)
    {
        for(int j = 0; j < mat[0].size(); j++)
        {
            if(mat[i][j] == 0)
                q.push({i, j});
            else
                mat[i][j] = INT_MAX;
        }
    }        
    while(!q.empty())
    {
        int i = q.front().first, j = q.front().second;
        q.pop();
        // left 
        if((j-1) >= 0 and mat[i][j-1] > (1 + mat[i][j])){
            mat[i][j-1] = 1 + mat[i][j];
            q.push({i, j-1});
        }
        // right
        if((j+1) < mat[0].size() and mat[i][j+1] > (1 + mat[i][j])){
            mat[i][j+1] = 1 + mat[i][j];
            q.push({i, j+1});
        }
        // down
        if((i+1) < mat.size() and mat[i+1][j] > (1 + mat[i][j])){
            mat[i+1][j] = 1 + mat[i][j];
            q.push({i+1, j});
        }
        // up
        if((i-1) >= 0 and mat[i-1][j] > (1 + mat[i][j])){
            mat[i-1][j] = 1 + mat[i][j];
            q.push({i-1, j});
        }
    }
    return mat;
}