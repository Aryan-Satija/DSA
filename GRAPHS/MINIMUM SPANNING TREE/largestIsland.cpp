// LEETCODE => Making A Large Island
#include <bits/stdc++.h>
using namespace std;
class disjointSet{
private:
    vector<int> size, parent;
public:
    disjointSet(int v){
        // assuming nodes vary from 0 to v-1
        size.resize(v, 1); 
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
        if(size[up_u] <= size[up_v]){
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else if(size[up_v] < size[up_u]){
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
    bool isSameComponent(int u, int v){
        return UltimateParent(u) == UltimateParent(v);
    }
    int componentSize(int u){
        int up_u = UltimateParent(u);
        return size[up_u];
    }
    int largestComponent(){
        int res = 0;
        for(auto comp_size : size) res = max(res, comp_size);
        return res;
    }
};
class Solution {
public:
    bool isValid(int i, int j, int n){
        if(i >= 0 && i < n && j >= 0 && j < n) return true;
        return false;
    }
    int largestIsland(vector<vector<int>>& grid) {
        // hashing algorithm (i, j) => ((n*i) + j)
        // nodes vary from 0 to ((n*n)-1)

        int n = grid.size();

        unordered_map<int, int> island;
        disjointSet ds(n*n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    vector<int> di = {-1, 1, 0, 0}, dj = {0, 0,-1, 1};
                    for(int x = 0; x < 4; x++){
                        int newi = i + di[x], newj = j + dj[x];
                        if(isValid(newi, newj, n) && grid[newi][newj])
                            ds.Union(n*i + j, n*newi + newj);
                    }
                }
            }
        }

        int res = ds.largestComponent();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    int island_size = 1;
                    unordered_set<int> ult_parents;
                    vector<int> di = {-1, 1, 0, 0}, dj = {0, 0,-1, 1};
                    for(int x = 0; x < 4; x++){
                        int newi = i + di[x], newj = j + dj[x];
                        if(isValid(newi, newj, n) && grid[newi][newj])
                            ult_parents.insert(ds.UltimateParent(newi*n + newj));
                    }
                    
                    for(auto itr : ult_parents)
                        island_size = island_size + ds.componentSize(itr);
                    res = max(res, island_size);
                }
            }
        }

        return res;

    }
};