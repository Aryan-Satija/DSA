// LEETCODE ->  Number of Ways to Arrive at Destination
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
class Solution {
public:
    int countPaths(int v, vector<vector<int>>& edge) {
        vector<vector<pair<int, int>>> adj(v);
        int e = edge.size();
        for(int i = 0; i < e; i++){
            adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
            adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
        }
        vector<long long int> distance(v, LONG_MAX);
        vector<long long int> ways(v, 0);
        distance[0] = 0; ways[0] = 1;
        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq; 
        pq.push({0, 0});
        while(!pq.empty()){
            long long int dst = pq.top().first;
            int nd = pq.top().second;
            pq.pop();
            for(auto p : adj[nd]){
                int nbr = p.first;
                long long int wt = p.second;
                if((dst + wt) < distance[nbr]){
                    ways[nbr] = ways[nd];
                    distance[nbr] = dst + wt;
                    pq.push({dst + wt, nbr});
                }
                else if((dst + wt) == distance[nbr])
                    ways[nbr] = (ways[nbr] + ways[nd])%mod;
            } 
        }
        return ways[v-1];
    }
};