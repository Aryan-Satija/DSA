// LEETCDOE -> Swim in Rising Water
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int swimInWater(vector<vector<int>>& grid) {
//         int n = grid.size();
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         vector<int> distance(n*n, 1e9);
//         pq.push({grid[0][0],0});
//         distance[0] = 0;
//         while(!pq.empty()){
//             auto [dist, node] = pq.top();
//             pq.pop();
//             int i = node/n, j = node%n;
//             if(node == (n*n - 1)) return dist;
//*             // up
//             if(i-1 >= 0){
//                 if(distance[n*(i-1) + j] > max(dist, grid[i-1][j])){
//                     distance[n*(i-1) + j] = max(dist, grid[i-1][j]);
//                     pq.push({distance[n*(i-1) + j], n*(i-1) + j});
//                 }
//             }
//*             // down
//             if(i+1 < n){
//                 if(distance[n*(i+1) + j] > max(dist, grid[i+1][j])){
//                     distance[n*(i+1) + j] = max(dist, grid[i+1][j]);
//                     pq.push({distance[n*(i+1) + j], n*(i+1) + j});
//                 }
//             }
//*             // left
//             if(j-1 >= 0){
//                 if(distance[n*i + j - 1] > max(dist, grid[i][j-1])){
//                     distance[n*i + j - 1] = max(dist, grid[i][j-1]);
//                     pq.push({distance[n*i + j - 1], n*i + j - 1});
//                 }
//             }
//*             // right
//             if(j+1 < n){
//                 if(distance[n*i + j + 1] > max(dist, grid[i][j+1])){
//                     distance[n*i + j + 1] = max(dist, grid[i][j+1]);
//                     pq.push({distance[n*i + j + 1], n*i + j + 1});
//                 }
//             }
//         }
//         return -1;
//     }
// };