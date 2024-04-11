// TC : O(ElogE)
#include <bits/stdc++.h>
using namespace std;
int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    vector<bool> isVis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    int MSTsum = 0;
    while (!pq.empty()) {
        int wt = pq.top().first, node = pq.top().second;
        pq.pop(); 
        if (!isVis[node]) {
            isVis[node] = true;
            MSTsum += wt;
            for (auto itr : adj[node]) {
                int nbr = itr.first, weight = itr.second;
                if (!isVis[nbr])
                    pq.push({weight, nbr});
            }
        }
    }
    return MSTsum;
}
