// CODING NINJAS -> Single Source Shortest Path
#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    vector<vector<int>> adj(n);
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    // SIMPLE BFS WOULD SOLVE THE QUESTION.
    vector<int> res(n, -1);
    queue<pair<int, int>> q;
    q.push({src, 0});
    vector<bool> isVis(n, false); isVis[src] = true;
    while(!q.empty()){
        int nd = q.front().first;
        int dst = q.front().second;
        q.pop();
        res[nd] = dst;
        for(auto nbr : adj[nd]){
            if(!isVis[nbr]){
                isVis[nbr] = true;
                q.push({nbr, 1 + dst});
            }
        }
    }
    return res;
}