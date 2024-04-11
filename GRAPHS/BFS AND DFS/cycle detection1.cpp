// CYCLE DETECTION IN AN UNDIRECTED GRAPH 
// (USING DFS)
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
bool isComponentCyclic(int node, int parent, vector<bool> &isVis, Graph g)
{
	isVis[node] = true;
	for(auto nbr : g.adj[node])
	{
		if(!isVis[nbr])
		{
			if(isComponentCyclic(nbr, node, isVis, g))
				return true;
		}
		else if(nbr != parent)
			return true;
	}
	return false;
}
bool isCyclic(Graph g)
{
	vector<bool> isVis(g.V, false);
	for(int i = 0; i < g.V; i++)
	{
		if(!isVis[i] and isComponentCyclic(i, -1, isVis, g))
			return true;
	}
	return false;
}