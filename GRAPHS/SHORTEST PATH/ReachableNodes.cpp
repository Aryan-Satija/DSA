// LEETCDOE -> Reachable Nodes In Subdivided Graph
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
//         vector<vector<pair<int, int>>> adj_list(n);
//         for(auto edge : edges){
//             adj_list[edge[0]].push_back({edge[1], edge[2]});
//             adj_list[edge[1]].push_back({edge[0], edge[2]});
//         }

//         vector<int> distance(n, INT_MAX);
//         distance[0] = 0;
        
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.push({0, 0});

//         while(!pq.empty()){
//             auto [reached_cnt, node] = pq.top();
//             pq.pop();
//             for(auto itr : adj_list[node]){
//                 auto [nbr, cost] = itr;
//                 if(reached_cnt + cost + 1 <= maxMoves && reached_cnt + cost + 1 < distance[nbr]){
//                     distance[nbr] = (reached_cnt + cost + 1);
//                     pq.push({reached_cnt + cost + 1, nbr});
//                 }
//             }
//         }
        
//         int res = 0;
//         for(auto cost : distance)
//             res = cost == INT_MAX ? res : res + 1;
        
//         for(auto edge : edges){
//             int cntA = max(0, maxMoves - distance[edge[0]]), cntB = max(0, maxMoves - distance[edge[1]]);

//             res = res + min(cntA + cntB, edge[2]);
//         }

//         return res;
//     }
// };