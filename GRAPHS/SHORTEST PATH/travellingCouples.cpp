// TRAVELLING COUPLES
/* 
AlgoLand has N cities. There are M pairs of cities connected by bidirectional trains. 
For travelling between any of the M pairs of cities, one can buy any of 3 types of train tickets 
which have the same cost irrespective of cities you are travelling between.
Ticket Type I : It costs C1
    but only males can buy and travel using it.

Ticket Type II : It costs C2
    but only females can buy and travel using it.

Ticket Type III : It costs C3
    but only couples in the same city travelling together can buy and travel using it.

A man is currently in city 1 while his wife is at city 2. 
Find the minimum cost they both need to collectively spend to reach their home which is in city N. 
They can both reach at different times or together, but they both have to reach home.
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, vector<vector<int>>&adj, int src) {
    vector<int> res(n+1, 1e9);
     queue<pair<int, int>> q;
    q.push({src, 0});
    vector<bool> isVis(n+1, false); isVis[src] = true;
    while(!q.empty()){
        int nd = q.front().first;
        int dst = q.front().second;
        q.pop();
        res[nd] = dst;
        for(auto nbr : adj[nd]){
            if(!isVis[nbr]){
                isVis[nbr] = true;
                q.push({nbr, 1 + dst});
            }
        }
    }
    return res;
}
int main() {
    int c1, c2, c3, n, m;
    cin >> c1 >> c2 >> c3 >> n >> m;
    vector<vector<int>> adj(n+1) ;
    int a, b;
    for(int i = 0; i < m; i++){
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    vector<int> shortestPathFromSrc1 = shortestPath(n, adj, 1); 
    vector<int> shortestPathFromSrc2 = shortestPath(n, adj, 2); 
    vector<int> shortestPathFromSrcn = shortestPath(n, adj, n); 
    
    int res = 1e9;
    int option;
    for(int i = 1; i <= n; i++){
      // man goes to i, female goes to i and then they go together
      option = c1*shortestPathFromSrc1[i] + c2*shortestPathFromSrc2[i] + c3*shortestPathFromSrcn[i];
      res = min(res, option);
    }
    
    cout << res << endl;
  
    return 0;
}
