// SC : O(V)
// TC : O(V + 2*E) [UNDIRECTED GRAPH]
// TC : O(V + E) [DIRECTED GRAPH]
#include <bits/stdc++.h> 
using namespace std;
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<vector<int>> adj(vertex);
    for(auto it : edges)
    {
        adj[it.first].push_back(it.second);
        adj[it.second].push_back(it.first);
    }

    vector<bool> isVis(vertex, false);
    vector<int> bfs;
    for(int i = 0; i < vertex; i++)
    {
        if(!isVis[i])
        {
            queue<int> q;
            q.push(i);
            isVis[i] = true;
            while(!q.empty())
            {
                int front = q.front();
                bfs.push_back(front);
                q.pop();
                for(auto it : adj[front])
                {
                    if(!isVis[it])
                    {
                        q.push(it);
                        isVis[it] = true;
                    }
                }
            }
        }   
    }
    return bfs;
}