// LEETCODE -> COURSE SCHEDULING-1
#include <bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // valid topological sort -> no cycle -> can schedule the courses
    // using kahn's algorithm ....
    vector<int> indegree(numCourses, 0); 
    vector<vector<int>> adj(numCourses);
    for(auto edge : prerequisites){
        indegree[edge[0]]++;
        adj[edge[1]].push_back(edge[0]);
    }
    queue<int> q;
    for(int i = 0; i < numCourses; i++){
        if(!indegree[i])
            q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int fnt = q.front(); q.pop();
        cnt++;
        for(auto nbr : adj[fnt]){
            if(!(--indegree[nbr]))
                q.push(nbr);
        }
    }
    return cnt == numCourses;
}