// LEETCODE -> REDUNDANT CONNECTION
#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
vector<int> parent;
vector<int> rank;    
    public:
    DisjointSet(int v){
        rank.resize(v+1,0);
        parent.resize(v+1);
        for(int i = 0; i <= v; i++) parent[i] = i;
    }
    int ultimate_parent(int node){
        if(parent[node] == node) return node;
        // path compression
        return parent[node] = ultimate_parent(parent[node]);
    }
    bool Union(int node1,int node2){
        int up_node1 = ultimate_parent(node1);
        int up_node2 = ultimate_parent(node2);
        if(up_node1 == up_node2) return false;
        if(rank[up_node1] > rank[up_node2])
            parent[up_node2] = up_node1;   
        else if(rank[up_node1] < rank[up_node2]) 
            parent[up_node1] = up_node2;
        else{
            parent[up_node2] = up_node1;
            rank[up_node1]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DisjointSet ds(edges.size());
        for(auto edge : edges){
            if(!ds.Union(edge[0], edge[1])) return edge;
        }
        // fake return
        return {};
    }
};