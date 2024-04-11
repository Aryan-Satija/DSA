// CYCLE DETECTION IN AN UNDIRECTED GRAPH 
// (USING DFS)
#include <bits/stdc++.h>
using namespace std;
bool detectCycle(int curr, vector<int> adjList[], vector<bool> isPathVisited, vector<bool> &isVis){
    isPathVisited[curr] = true;
    isVis[curr] = true;
    for(auto nbr : adjList[curr])
    {
        if(!isVis[nbr] and detectCycle(nbr, adjList, isPathVisited, isVis))
            return true;
        if(isPathVisited[nbr]) return true;
    }
    return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
    vector<int> adjList[v];
    for(auto edge : edges)
        adjList[edge[0]].push_back(edge[1]);
    vector<bool> isVis(v, false);
    // detect cycle
    for(int i = 0; i < v; i++)
    {
        if(!isVis[i])
        {
            vector<bool> isPathVisited(v, false);
            if(detectCycle(i, adjList, isPathVisited, isVis))
                return true;
        }
    }
    return false;
}
