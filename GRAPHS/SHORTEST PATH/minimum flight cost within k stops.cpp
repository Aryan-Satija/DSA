// LEETCODE -> Cheapest Flights Within K Stops
// dfs method
#include <bits/stdc++.h>
using namespace std;
class cmp{
    public:
    bool operator()(vector<int> a, vector<int> b){
        if(a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int, int>>> adj(n);
        for(auto edge : flights)
            adj[edge[0]].push_back({edge[1], edge[2]});
        
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;  // {stops_left, cost_till_now, node}
        vector<int> flightCost(n, INT_MAX);
        pq.push({k, 0, src}); flightCost[src] = 0; 
        while(!pq.empty()){
            vector<int> tmp = pq.top(); pq.pop();
            int stops_left = tmp[0], cost_till_now = tmp[1], node = tmp[2];
            if(stops_left >= 0){
                for(auto itr : adj[node]){
                    int nbr = itr.first, wt = itr.second;
                    if(cost_till_now + wt < flightCost[nbr]){
                        flightCost[nbr] = cost_till_now + wt;
                        pq.push({stops_left-1, flightCost[nbr], nbr});
                    }
                }
            }
        }
        return flightCost[dst] == INT_MAX ? -1 : flightCost[dst];
    }
};