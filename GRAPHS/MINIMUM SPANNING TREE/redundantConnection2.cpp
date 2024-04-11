// LLETCODE -> REDUNDANT CONNECTION 2
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int v = edges.size();
        vector<int> indegree(v+1, 0);
        for(auto edge : edges)
            indegree[edge[1]]++;

        bool flag = false;
        for(int i = 1; i <= v; i++){
            if(!indegree[i]){
                flag = true;
                break;
            }
        }

        if(flag){
            cout << "hello" << endl;
            // root node not involved in the cycle
            vector<vector<int>> black_listed_edges; 
            for(auto edge : edges){    
                if(indegree[edge[1]] > 1) black_listed_edges.push_back(edge); 
            }
            DisjointSet ds(v+1);
            for(auto edge : edges){
                if(edge != black_listed_edges[0] && edge != black_listed_edges[1])
                    ds.Union(edge[0], edge[1]);
            }
            // ordering very important in this return statement
            return ds.Union(black_listed_edges[0][0], black_listed_edges[0][1]) ? black_listed_edges[1] : black_listed_edges[0];
        }

        // root node involved in the cycle
        DisjointSet ds(v+1);
        for(auto edge : edges){
            if(!ds.Union(edge[0], edge[1]))
                return edge;
        }
        return {};
    }
};