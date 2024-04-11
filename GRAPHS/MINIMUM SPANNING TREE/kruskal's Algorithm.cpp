// TC: O(E*logE)
#include <bits/stdc++.h>
using namespace std;
class disjointSet{
private:
    vector<int> rank, parent;
public:
    disjointSet(int v){
        rank.resize(v, 0); 
        parent.resize(v);
        for(int i = 0; i < v; i++)
            parent[i] = i;
    }
    int UltimateParent(int n){
        if(parent[n] == n)
            return n;
        // PATH COMPRESSION
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
bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    int res = 0;
    disjointSet ds(n);
    for(auto edge : edges){
        int u = edge[0], v = edge[1], wt = edge[2];
        if(!ds.isSameComponent(u, v)){
            ds.Union(u, v);
            res += wt;
        }
    }
    return res;
}