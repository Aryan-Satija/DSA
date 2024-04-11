// LEETCODE ->  Minimum Time to Visit a Cell In a Grid

//* hashing formula => (i, j) => (m*i + j)
//* hash => (i = (hash/m) && j = (hash%m))

// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int minimumTime(vector<vector<int>>& grid) {
//         if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
//         int n = grid.size(), m = grid[0].size();
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//         pq.push({0, 0});
//         vector<int> time_to_reach(n*m, INT_MAX);
//         time_to_reach[0] = 0;
//         while(!pq.empty()){
//             auto [time, hash] = pq.top();
//             pq.pop();
//             int i = hash/m, j = hash%m;
//*             // up 
//             int time_to_reach_nbr;
//             if(i >= 1){
//                 time_to_reach_nbr = max(time+1, grid[i-1][j] + (grid[i-1][j]+time+1)%2);
//                 if(time_to_reach[(m*(i-1)) + j] > time_to_reach_nbr){
//                     time_to_reach[(m*(i-1)) + j] = time_to_reach_nbr;
//                     pq.push({time_to_reach_nbr, (m*(i-1)) + j});
//                 }
//             }
//*             // down
//             if(i < n-1){
//                 time_to_reach_nbr = max(time+1, grid[i+1][j] + (grid[i+1][j]+time+1)%2);
//                 if(time_to_reach[(m*(i+1)) + j] > time_to_reach_nbr){
//                     time_to_reach[(m*(i+1)) + j] = time_to_reach_nbr;
//                     pq.push({time_to_reach_nbr, (m*(i+1)) + j});
//                 }
//             }
//*             // left
//             if(j >= 1){
//                 time_to_reach_nbr = max(time+1, grid[i][j-1] + (grid[i][j-1]+time+1)%2);
//                 if(time_to_reach[(m*i) + j - 1] > time_to_reach_nbr){
//                     time_to_reach[(m*i) + j - 1] = time_to_reach_nbr;
//                     pq.push({time_to_reach_nbr, (m*i) + j - 1});
//                 }
//             }
//*             // right
//             if(j < m-1){
//                 time_to_reach_nbr = max(time+1, grid[i][j+1] + (grid[i][j+1]+time+1)%2);
//                 if(time_to_reach[(m*i) + j+1] > time_to_reach_nbr){
//                     time_to_reach[(m*i) + j+1] = time_to_reach_nbr;
//                     pq.push({time_to_reach_nbr, (m*i) + j + 1});
//                 }
//             }
//         }
//         return time_to_reach[(m*n) - 1];
//     }
// };