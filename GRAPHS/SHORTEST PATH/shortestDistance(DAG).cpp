// CODING NINJAS -> Shortest Path in DAG
#include <bits/stdc++.h>
using namespace std;
void f(int curr, vector<vector<pair<int, int>>> &adj, vector<bool> &isVis, stack<int> &topSort){
    isVis[curr] = true;
    for(auto nbr : adj[curr]){
        if(!isVis[nbr.first])
            f(nbr.first, adj, isVis, topSort);
    }
    topSort.push(curr);
}
vector<int> shortestPathInDAG(int v, int e, vector<vector<int>> &edges){
    vector<vector<pair<int, int>>> adj(v);
    for(auto edge : edges)
        adj[edge[0]].push_back({edge[1], edge[2]});
    
    stack<int> topSort;
    vector<bool> isVis(v, false);
    for(int i = 0; i < v; i++){
        if(!isVis[i])
            f(i, adj, isVis, topSort);
    }
    vector<int> res(v, -1);
    res[0] = 0;
    while(!topSort.empty()){
        int tp = topSort.top();
        if(res[tp] != -1){
            for(auto edge : adj[tp]){
                int nbr = edge.first, wt = edge.second;
                res[nbr] = (res[nbr] == -1 or res[tp] + wt < res[nbr]) ? (res[tp] + wt): res[nbr];
            }
        }
        topSort.pop();
    }
    return res;
}