// LEETCODE -> Number of Restricted Paths From First to Last Node
// ALWAYS PREFER PASS BY REFERENCE OVER PASS BY VALUE
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int v, int e, int src)
    {
        vector<int> distance(v+1, INT_MAX); distance[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0, src});
        while(!pq.empty()){
            int dst = pq.top().first;
            int nd = pq.top().second;
            pq.pop();
            for(auto p : adj[nd]){
                int nbr = p.first;
                int wt = p.second;
                if((dst + wt) < distance[nbr]){
                    distance[nbr] = dst + wt;
                    pq.push({dst + wt, nbr});
                }
            } 
        }
        return distance;
    }
    int dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &distance, vector<int> &dp){
        if(node == (distance.size() - 1))
            return 1;
        if(dp[node] != -1)
            return dp[node];
        int paths = 0;
        for(auto itr : adj[node]){
            int nbr = itr.first;
            if(distance[node] > distance[nbr])
                paths = (paths + dfs(nbr, adj, distance, dp))%mod;
        }
        return dp[node] = paths;
    }
    int countRestrictedPaths(int v, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(v+1);
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<int> distance = dijkstra(adj, v, edges.size(), v);
        vector<int> dp(v+1, -1);
        return dfs(1, adj, distance, dp);
    }
};