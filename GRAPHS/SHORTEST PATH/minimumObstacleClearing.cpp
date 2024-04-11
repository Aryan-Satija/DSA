// LEETCDOE -> Minimum Obstacle Removal to Reach Corner
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int minimumObstacles(vector<vector<int>>& grid) {
//         int n = grid.size(), m = grid[0].size();
//         vector<int> distance(n*m, INT_MAX);
//         distance[0] = 0;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.push({0, 0});
//         while(!pq.empty()){
//             auto [obstacles, node] = pq.top();
//             pq.pop();
//             if(node == (n*m) - 1) return obstacles;
            
//             // left
//             if(node%m != 0){
//                 if(distance[node-1] > obstacles + grid[(node-1)/m][(node-1)%m]){
//                     distance[node-1] = obstacles + grid[(node-1)/m][(node-1)%m];
//                     pq.push({distance[node-1], node-1});
//                 }
//             }

//             // up
//             if(node >= m){
//                 if(distance[node-m] > obstacles + grid[(node-m)/m][(node-m)%m]){
//                     distance[node-m] = obstacles + grid[(node-m)/m][(node-m)%m];
//                     pq.push({distance[node-m], node-m});
//                 }
//             }

//             // down
//             if(node < m*(n-1)){
//                 if(distance[node+m] > obstacles + grid[(node+m)/m][(node+m)%m]){
//                     distance[node+m] = obstacles + grid[(node+m)/m][(node+m)%m];
//                     pq.push({distance[node+m], node+m});
//                 }
//             }

//             // right
//             if(node%m != m-1){
//                 if(distance[node+1] > obstacles + grid[(node+1)/m][(node+1)%m]){
//                     distance[node+1] = obstacles + grid[(node+1)/m][(node+1)%m];
//                     pq.push({distance[node+1], node+1});
//                 }
//             }

//         }        
//         return -1;
//     }
// };