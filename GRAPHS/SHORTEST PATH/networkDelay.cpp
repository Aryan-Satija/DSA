// LEETCODE ->  Network Delay Time
#include <bits/stdc++.h>
using namespace std;
int networkDelayTime(vector<vector<int>>& times, int v, int src) {
    int e = times.size();
    vector<vector<pair<int, int>>> adj(v+1);
    for(int i = 0; i < e; i++)
        adj[times[i][0]].push_back({times[i][1], times[i][2]});
    vector<int> tm(v+1, INT_MAX);
    tm[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    pq.push({0, src});
    while(!pq.empty()){
        int dst = pq.top().first;
        int nd = pq.top().second;
        pq.pop();
        for(auto p : adj[nd]){
            int nbr = p.first;
            int wt = p.second;
            if((dst + wt) < tm[nbr]){
                tm[nbr] = dst + wt;
                pq.push({dst + wt, nbr});
            }
        } 
    }
    int res = INT_MIN;
    for(int i = 1; i <= v; i++){
        if(tm[i] == INT_MAX)
            return -1;
        res = max(res, tm[i]);
    }
    return res;
}