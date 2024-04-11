#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    vector<vector<int>> adjList(n);
    for(auto edge : edges)
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }    
    return adjList;
}