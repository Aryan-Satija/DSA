// BELLMAN FORD ALGORITHM
// USED TO FIND OUT THE SHORTEST PATH FROM THE SOURCE NODE TO ALL THE OTHER NODES OF THE GRAPH
// TC : O(E*V) [BELLMAN FORD]
// TC : O(E*LOGV) [DIJKSTRA'S]
// BELLMAN FORD ALGORITHM CAN BE USED ON A GRAPH WITH NEGATIVE WEIGHTS
// IT CAN ALSO DETECT NEGATIVE CYCLES
// IN CASE OF NEGATIVE CYCLES, DIJKSTRA'S ALGORITHM GOES INTO A TLE LOOP
#include <bits/stdc++.h>
using namespace std;
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> distance(n, 1e9);
    distance[src] = 0;
    for(int i = 1; i < n; i++){
        for(auto edge : edges){
            if(distance[edge[0]] != 1e9)
                distance[edge[1]] = min(distance[edge[1]], distance[edge[0]] + edge[2]);
        }
    }
    return distance;
}