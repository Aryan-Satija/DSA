// LEETCODE -> EVALUATE DIVISION
#include <bits/stdc++.h>
using namespace std;
double dfs(string src, string dst, unordered_map<string, vector<pair<string, double>>> adj, unordered_map<string, bool> &isVisited){
    if(src == dst)
        return 1.0;
    isVisited[src] = true;
    for(auto itr : adj[src]){
        string nbr = itr.first;
        double wt = itr.second;
        if(!isVisited[nbr]){
            double tmp = dfs(nbr, dst, adj, isVisited);
            if(tmp != -1.0)
                return wt*tmp;
        }
    }
    return -1.0;
}
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    unordered_map<string, vector<pair<string, double>>> adj;
    for(int i = 0; i < equations.size(); i++){
        adj[equations[i][0]].push_back({equations[i][1], values[i]});
        adj[equations[i][1]].push_back({equations[i][0], (1/values[i])});
    }
    vector<double> res;
    for(auto query : queries){
        string src = query[0], dst = query[1];
        unordered_map<string, bool> isVisited;
        if(adj.find(src) != adj.end() and adj.find(dst) != adj.end())
            res.push_back(dfs(src, dst, adj, isVisited));
        else res.push_back(-1.00);
    }
    return res;
