// topological sort1 (kahn's algorithm)
#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(vector<vector<int>> &graph, int e, int v) {
    vector<int> indegree(v, 0);
    vector<vector<int>> adjList(v);
    for(auto edge : graph){
        indegree[edge[1]]++;
        adjList[edge[0]].push_back(edge[1]);
    }

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
