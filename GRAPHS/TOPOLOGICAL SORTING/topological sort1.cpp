// topological sort1 (dfs)
#include <bits/stdc++.h>
using namespace std;
void dfs(int curr, vector<vector<int>> adj, vector<bool> &isVis, stack<int> &s)
{
    isVis[curr] = true;   
    for(auto nbr : adj[curr])
    {
        if(!isVis[nbr])
            dfs(nbr, adj, isVis, s);
    }
    s.push(curr);
}
vector<int> topologicalSort(vector<vector<int>> &graph, int e, int v) {
    vector<vector<int>> adj(v);
    for(auto edge : graph)
        adj[edge[0]].push_back(edge[1]);
    stack<int> s;
    vector<bool> isVis(v, false);
    for(int i = 0; i < v; i++) {
        if(!isVis[i])
            dfs(i, adj, isVis, s);
    }
    vector<int> res;
    while(!s.empty())
    {
        res.push_back(s.top());
        s.pop();
    }
    return res;
}