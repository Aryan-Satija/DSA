// LEETCODE ->  Most Stones Removed with Same Row or Column
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
    int removeStones(vector<vector<int>>& stones) {
        int max_r = INT_MIN, max_c = INT_MIN;
        for(auto loc : stones){
            max_r = max(max_r, loc[0]);
            max_c = max(max_c, loc[1]);
        }
        disjointSet st(max_r + max_c + 2);
        unordered_map<int, bool> mp;
        for(auto loc: stones){
            st.Union(loc[0], loc[1] + max_r + 1);
            mp[loc[0]] = true;
            mp[loc[1] + max_r + 1] = true;
        }
        int cntc = 0;
        for(auto itr : mp){
            if(st.UltimateParent(itr.first) == itr.first)
                cntc++;
        }
        return (stones.size() - cntc);
    }
};