#include <bits/stdc++.h>
using namespace std;
bool detectCycle(int curr, vector<vector<int>> adjList, vector<int> &isVis){
    isVis[curr] = 2;
    for(auto nbr : adjList[curr])
    {
        if(isVis[nbr] == 0 and detectCycle(nbr, adjList, isVis))
            return true;
        else if(isVis[nbr] == 2) 
            return true;
    }
    isVis[curr] = 1;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int v = graph.size();
    vector<int> res;
    vector<int> isVis(v, 0);
    for(int i = 0; i < v; i++)
    {
        if(isVis[i] == 0)
            detectCycle(i, graph, isVis);
    }
    for(int i = 0; i < v; i++)
    {
        if(isVis[i] == 1)
            res.push_back(i);
    }
    return res;
}