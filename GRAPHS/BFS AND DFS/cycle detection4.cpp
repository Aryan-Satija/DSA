// USING KAHN'S ALGORITHM ....
#include <bits/stdc++.h>
using namespace std;
int detectCycleInDirectedGraph(int v, vector<pair<int, int>> & graph) {
    vector<int> indegree(v + 1, 0);
    vector<vector<int>> adjList(v + 1);
    for(auto edge : graph){
        indegree[edge.second]++;
        adjList[edge.first].push_back(edge.second);
    }
    queue<int> q;
    for(int i = 1; i <= v; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int fnt = q.front();
        q.pop();
        cnt++;
        for(auto nbr : adjList[fnt])
        {
            if(--indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    return (cnt != v);
}