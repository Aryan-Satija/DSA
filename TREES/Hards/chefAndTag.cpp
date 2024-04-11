// CODECHEF -> CHEF AND TAG
// #include <bits/stdc++.h>
// using namespace std;
// int solve(int node, int dist, vector<vector<int>> &adj, vector<bool> &isVis, vector<vector<int>> &data){
//     if(dist >= data[node][1]) return data[node][0];
//     int max_tagged = 0;
//     isVis[node] = true; 
//     for(auto nbr : adj[node]){
//         if(!isVis[nbr])
//             max_tagged = max(max_tagged, solve(nbr, dist+1, adj, isVis, data));
//     }
//     return max_tagged;
// }
// pair<int, int> traverse(int node, vector<vector<int>> &adj, vector<bool> &isVis, vector<vector<int>> &data){
//     if(adj[node].size() == 1 && isVis[adj[node][0]]) {
//         data[node] = {0, 0};
//         return {1, 1}; 
//     }
//     isVis[node] = true;
//     int total_leaf_nodes = 0, min_height = 1e9;
//     for(auto nbr : adj[node]){
//         if(!isVis[nbr]){
//             auto [leaf_nodes, height] = traverse(nbr, adj, isVis, data);
//             total_leaf_nodes += leaf_nodes;
//             min_height = min(height, min_height);
//         }
//     }
//     data[node] = {total_leaf_nodes, min_height};
//     isVis[node] = false;
//     return {total_leaf_nodes, 1 +  min_height};
// }
// int main() {
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<vector<int>> adj(n+1);
//         for(int i = 1; i < n; i++){
//             int a, b;
//             cin >> a >> b;
//             adj[a].push_back(b);
//             adj[b].push_back(a);
//         }
        
        
//         vector<bool> isVis(n+1, false);
//         vector<vector<int>> data(n+1);
        
//         traverse(1, adj, isVis, data);
        
//         cout << solve(1, 0, adj, isVis, data) << endl;
        
//     }
// }