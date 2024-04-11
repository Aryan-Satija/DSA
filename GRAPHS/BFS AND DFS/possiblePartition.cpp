// LEETCODE -> Possible Bipartition
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBipartite(int node, int currentColor, vector<vector<int>> &adj, vector<int> &color){
        color[node] = currentColor;
        for(auto nbr : adj[node]){
            if(!color[nbr]){
                if(!isBipartite(nbr, -1*currentColor, adj, color)) return false;
            }
            else{
                if(color[nbr] == currentColor) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(auto edge : dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n+1, 0);
        // -1 => color A
        // 0 => notVisited;
        // 1 => color B
        
        for(int i = 1; i <= n; i++){
            if(!color[i]){
                if(!isBipartite(i, 1, adj, color)) return false;
            }
        }
        return true;
    }
};