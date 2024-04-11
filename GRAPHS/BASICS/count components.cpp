// CODING NINJAS -> FIND THE NUMBER OF PROVINCES
#include <bits/stdc++.h>
using namespace std;
void DFS(int curr, vector<bool> &isVisited, vector<int> adjList[])
{
    isVisited[curr] = true;
    for(auto node : adjList[curr])
    {
        if(!isVisited[node])
            DFS(node, isVisited, adjList);
    }   
}
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // ADJACENCY MATRIX TO ADJACENCY LIST...
    vector<int> adjList[n];
    for(int i = 0; i < n; i++)
    {
        for(int j = (i+1); j < n; j++)
        {
            if(roads[i][j])
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    int components = 0;
    vector<bool> isVisited(n, false);
    for(int i = 0; i < n; i++)
    {   
        if(!isVisited[i])
        {
            // COLOR ALL THE NODES OF A COMPONENT
            DFS(i, isVisited, adjList);
            components++;
        }
    }
    return components;
}