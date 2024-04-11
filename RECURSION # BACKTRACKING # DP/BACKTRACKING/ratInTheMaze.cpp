// CODING NINJAS -> RAT IN THE MAZE
#include <bits/stdc++.h>
using namespace std;
void f(int r, int c, int n, string path, vector<vector<int>> &mat, vector<string> &res){
    if(r < 0 or c < 0 or r >= n or c >= n or mat[r][c] == 0)
        return;
    if(r == n-1 and c == n-1){
        res.push_back(path);
        return;
    }
    mat[r][c] = 0;
    // left 
    f(r, c-1, n, path + "L", mat, res);
    // right
    f(r, c+1, n, path + "R", mat, res);
    // up
    f(r-1, c, n, path + "U", mat, res);
    // down
    f(r+1, c, n, path + "D", mat, res);
    mat[r][c] = 1;
}
vector<string> ratMaze(vector<vector<int>> &mat) {
    int n = mat.size();
    if(mat[0][0] == 0 or mat[n-1][n-1] == 0)
        return {};
    vector<string> res;
    f(0, 0, n, "", mat, res);
    return res;
}