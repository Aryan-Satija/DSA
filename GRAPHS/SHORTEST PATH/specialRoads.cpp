// LEETCODE -> Minimum Cost of a Path With Special Roads
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long int
// class Solution {
// public:
//     unordered_map<ll, int> cood_hash;
//     vector<vector<int>> nodes;
//     ll multiplier = 1e5;
//     void add_node(vector<int> cood){
//         ll hash = ((multiplier*cood[0]) + cood[1]);
//         if(cood_hash.find(hash) == cood_hash.end()){
//             cood_hash[hash] = nodes.size();
//             nodes.push_back(cood);
//         }
//     } 
//     int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoad) {
//         if(start == target) return 0;
//         add_node(start);
//         add_node(target);
//         for(auto road : specialRoad){
//             add_node({road[0], road[1]});
//             add_node({road[2], road[3]});
//         }
//         int v = nodes.size();

//         vector<vector<pair<int, int>>> adj_list(v);
//         for(int i = 0; i < v; i++){
//             for(int j = 0; j < v; j++){
//                 int x1 = nodes[i][0], y1 = nodes[i][1], x2 = nodes[j][0], y2 = nodes[j][1];
//                 int manhattan_distance = abs(x2-x1) + abs(y2-y1);
//                 adj_list[i].push_back({j, manhattan_distance});
//             }
//         }
//         for(auto road : specialRoad){
//             int x1 = road[0], y1 = road[1], x2 = road[2], y2 = road[3], cost = road[4];
//             int manhattan_distance = abs(x2-x1) + abs(y2-y1);
//             if(cost < manhattan_distance){
//                 ll source_hash = ((multiplier*x1) + y1), target_hash = ((multiplier*x2) + y2);
//                 adj_list[cood_hash[source_hash]].push_back({cood_hash[target_hash], cost});
//             } 
//         }
//         vector<int> distance(v, INT_MAX);
//         distance[0] = 0;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.push({0, 0});
//         while(!pq.empty()){
//             auto [dist, node] = pq.top();
//             pq.pop();
//             for(auto itr : adj_list[node]){
//                 auto [nbr, nbr_distance] = itr;
//                 if(dist + nbr_distance < distance[nbr]){
//                     distance[nbr] = dist + nbr_distance;
//                     pq.push({distance[nbr], nbr});
//                 }
//             }
//         }
//         return distance[1];
//     }
// };