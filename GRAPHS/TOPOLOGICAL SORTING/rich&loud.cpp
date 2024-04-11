// LEETCODE -> Loud and Rich
#include <bits/stdc++.h>
using namespace std;
int dfs(int curr, vector<vector<int>>& adj, vector<int>& quiet, vector<int>& res) {
    if (res[curr] != -1)
        return res[curr];
    
    int qfactor = quiet[curr];
    int loudest_person = curr;  // Initialize loudest person as the current person
    
    for (int nbr : adj[curr]) {
        int candidate = dfs(nbr, adj, quiet, res);
        if (quiet[candidate] < quiet[loudest_person]) {
            loudest_person = candidate;
        }
    }
    
    return res[curr] = loudest_person;
}

vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    int n = quiet.size();
    
    vector<vector<int>> adj(n);
    for (auto edge : richer)
        adj[edge[1]].push_back(edge[0]);
    
    vector<int> res(n, -1);
    for (int i = 0; i < n; i++) {
        if (res[i] == -1) {
            res[i] = dfs(i, adj, quiet, res);
        }
    }
    
    return res;
}