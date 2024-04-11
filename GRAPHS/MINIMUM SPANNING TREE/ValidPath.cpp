// LEETCODE -> Find if Path Exists in Graph
#include <bits/stdc++.h>
using namespace std;
class disjointSet{
private:
    vector<int> rank, parent;
public:
    disjointSet(int v){
        // assuming nodes vary from 0 to v-1
        rank.resize(v, 0); 
        parent.resize(v);
        for(int i = 0; i < v; i++)
            parent[i] = i;
    }
    int UltimateParent(int n){
        if(parent[n] == n)
            return n;
        // path compression
        return parent[n] = UltimateParent(parent[n]);
    }
    void Union(int u, int v){
        int up_u = UltimateParent(u); 
        int up_v = UltimateParent(v);
        if(up_u == up_v)
            return;
        if(rank[up_u] < rank[up_v])
            parent[up_u] = up_v;
        else if(rank[up_v] < rank[up_u])
            parent[up_v] = up_u;
        else{
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }
    bool isSameComponent(int u, int v){
        return UltimateParent(u) == UltimateParent(v);
    }

};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        disjointSet ds(n);
        for(auto edge : edges)
            ds.Union(edge[0], edge[1]);
        return ds.isSameComponent(source, destination);
    }
};