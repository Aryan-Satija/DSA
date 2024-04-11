// SC : O(V)
// TC : O(V + 2*E) [UNDIRECTED GRAPH]
// TC : O(V + E) [DIRECTED GRAPH]
#include <bits/stdc++.h>
using namespace std;
void dfsTraversal(int node, vector<vector<int>> adj, vector<bool> &isVis, vector<int> &componentsDfs)
{
    componentsDfs.push_back(node);
    isVis[node] = true;
    for(auto it : adj[node])
    {
        if(!isVis[it])
            dfsTraversal(it, adj, isVis, componentsDfs);   
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<bool> isVis(V, false);
    // because components of the graph may be possible....
    vector<vector<int>> dfs;
    for(int i = 0; i < V; i++)
    {
        if(!isVis[i])
        {
            vector<int> componentsDfs;
            dfsTraversal(i, adj, isVis, componentsDfs);
            dfs.push_back(componentsDfs);
        }
    }
    return dfs;
}