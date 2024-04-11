// LEETCODE -> Sort Items by Groups Respecting Dependencies
#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &adjList, vector<int> &indegree, int v) {
    queue<int> q;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> res;
    while(!q.empty()){
        int fnt = q.front();
        q.pop();
        res.push_back(fnt);
        for(auto nbr : adjList[fnt])
        {
            if(--indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    return res;
}
vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    int grp = m;
    for(int i = 0; i < n; i++){
        if(group[i] == -1)
            group[i] = grp++;
    }
    vector<int> indegree(n, 0), group_indegree(grp, 0);
    vector<vector<int>> adjList(n), group_adjList(grp); 
    for(int i = 0; i < n; i++){
        for(auto nd : beforeItems[i]){
            adjList[nd].push_back(i);
            indegree[i]++;
            if(group[nd] != group[i]){
                group_adjList[group[nd]].push_back(group[i]);
                group_indegree[group[i]]++;
            }
        }
    }
    vector<int> groupTopSort = topologicalSort(group_adjList, group_indegree, grp);
    if(groupTopSort.size() != grp)  
        return {};
    vector<int> TopSort = topologicalSort(adjList, indegree, n);
    if(TopSort.size() != n)  
        return {};
    vector<vector<int>> GrpMp(grp);
    for(auto i : TopSort)
        GrpMp[group[i]].push_back(i);
    
    vector<int> res;
    for(auto gp : groupTopSort){
        for(auto i : GrpMp[gp])
            res.push_back(i);
    }
    return res;
}