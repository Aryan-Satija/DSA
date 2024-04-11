// LEETCODE- > BLOODFILL ALGORITHM
#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>>& image,int sr, int sc, int color, int newColor)
{
    image[sr][sc] = newColor;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(!q.empty())
    {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr >= 0 and nr < image.size() and nc >= 0 and nc < image[0].size() and image[nr][nc] == color)
            {
                image[nr][nc] = newColor;
                q.push({nr, nc});
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if(image[sr][sc] == color)
        return image;
    BFS(image, sr, sc, image[sr][sc], color);
    return image;
}