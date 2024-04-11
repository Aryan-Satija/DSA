// CODING NINJAS -> Dijkstra's shortest path
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &edge, int v, int e, int src)
{
	vector<vector<pair<int, int>>> adj(v);
	for(int i = 0; i < e; i++){
          adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
          adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
    }
	vector<int> distance(v, INT_MAX);
	distance[src] = 0;
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
// TC: ELOG(V)
