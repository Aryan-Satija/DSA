// LEETCODE -> Path with Maximum Probability
#include <bits/stdc++.h>
using namespace std;
double maxProbability(int v, vector<vector<int>>& edges, vector<double>& succProb, int src, int dst) {
    vector<pair<int, double>> adj[v];
    int e = edges.size();
    for(int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }
    priority_queue<pair<double, int>> pq;
    vector<double> probability(v, 0.0);
    pq.push({1.0, src}); probability[src] = 1.0;
    while(!pq.empty()){
        double prob = pq.top().first; int node = pq.top().second;
        pq.pop();
        for(auto itr : adj[node]){
            int nbr = itr.first; double wt = itr.second;
            if(prob*wt > probability[nbr]){
                probability[nbr] = prob*wt;
                pq.push({probability[nbr], nbr});
            }
        }
    }
    return probability[dst];
}