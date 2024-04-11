// LEETCODE -> Min Cost to Connect All Points

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
        return parent[n] = UltimateParent(parent[n]);
    }
    bool Union(int u, int v){
        int up_u = UltimateParent(u); 
        int up_v = UltimateParent(v);
        if(up_u == up_v)
            return false;
        if(rank[up_u] < rank[up_v])
            parent[up_u] = up_v;
        else if(rank[up_v] < rank[up_u])
            parent[up_v] = up_u;
        else{
            parent[up_u] = up_v;
            rank[up_v]++;
        }
        return true;
    }
    bool isSameComponent(int u, int v){
        return UltimateParent(u) == UltimateParent(v);
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int v = points.size();
        disjointSet ds(v);
        unordered_map<int, pair<int, int>> mp;
        
        for(int i = 0; i < v; i++)
            mp[i] = make_pair(points[i][0], points[i][1]);
        vector<vector<int>> edges;
        for(int i = 0; i < v; i++){
            for(int j = i+1; j < v; j++){
            int x1 = mp[i].first, x2 = mp[j].first, y1 = mp[i].second, y2 = mp[j].second;
            int manhattanDistance = abs(x1 - x2) + abs(y1 - y2); 
            edges.push_back({manhattanDistance, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        int res = 0;
        for(auto edge : edges){
            int manhattanDistance = edge[0], nd1 = edge[1], nd2 = edge[2];
            if(ds.Union(nd1, nd2))
                res += manhattanDistance;
        }
        return res;
    }
};