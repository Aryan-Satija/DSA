// LEETCODE -> COURSE SCHEDULING-2
#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(numCourses);
    for(auto edge : prerequisites){
        indegree[edge[0]]++;
        adj[edge[1]].push_back(edge[0]);
    }
    queue<int> q;
    for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> res;
    while(!q.empty()){
        int fnt = q.front();
        q.pop();
        res.push_back(fnt);
        for(auto nbr : adj[fnt])
        {
            if(--indegree[nbr] == 0)
                q.push(nbr);
        }
    }
    vector<int> emp;
    return res.size() == numCourses ? res : emp;
}