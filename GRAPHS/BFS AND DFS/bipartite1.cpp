// LEETCODE -> Is Graph Bipartite
// USING BFS....
#include <bits/stdc++.h>
using namespace std;
bool isComponentBipartite(int node, vector<vector<int>>& graph, vector<int> &color){
    queue<int> q;
    q.push(node);
    color[node] = 1;
    while(!q.empty())
    {
        int nd = q.front();
        q.pop();
        for(auto nbr : graph[nd])
        {
            if(color[nbr] == 0)
            {
                color[nbr] = (color[nd] == 1) ? 2 : 1;
                q.push(nbr);
            }
            else if(color[nbr] == color[nd])
                return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), 0);
    // 0 -> not colored
    // 1 -> colored with color-1
    // 2 -> colored with color-2
    for(int i = 0; i < graph.size(); i++)
    {
        if(color[i] == 0)
        {
            if(!isComponentBipartite(i, graph, color))
                return false;
        }
    }
    return true;
}