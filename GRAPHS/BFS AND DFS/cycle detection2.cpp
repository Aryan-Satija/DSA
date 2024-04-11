// CYCLE DETECTION IN AN UNDIRECTED GRAPH 
// (USING BFS)
#include <bits/stdc++.h>
using namespace std;
class Graph
{
    
public:
	int V;    
    list<int> *adj;
    /*
        ...constructor
    */
};
bool isCyclic(Graph g)
{
	vector<bool> isVis(g.V, false);
	for(int i = 0; i < g.V; i++)
	{
		if(!isVis[i])
		{
			queue<pair<int, int>> q;
			q.push({i, -1});
			isVis[i] = true;
			while(!q.empty())
			{
				int nd = q.front().first;
				int par = q.front().second;
				q.pop();
				for(auto nbr : g.adj[nd])
				{
					if(isVis[nbr]){
						if(nbr != par)
							return true;
					}
					else{
						isVis[nbr] = true;
						q.push({nbr, nd});
					}
				}
			}
		}
	}
	return false;
}