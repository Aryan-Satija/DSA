// LEETCODE ->  Longest Cycle in a Graph
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int node, vector<bool> &isVis, vector<int> &nbr){
        if(isVis[node]) return 0;
        isVis[node] = true;
        return 1 + f(nbr[node], isVis, nbr);
    }
    int longestCycle(vector<int>& nbr) {
        int n = nbr.size();
        vector<int> indegree(n, 0);
        for(auto node : nbr){
            if(node != -1) indegree[node]++;
        }
        queue<int> q;
        vector<bool> isVis(n, false);
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        } 
        while(!q.empty()){
            int node = q.front(); q.pop();
            isVis[node] = true;
            if(nbr[node] != -1 and --indegree[nbr[node]] == 0) q.push(nbr[node]);
        }
        int cycle = -1;
        for(int i = 0; i < n; i++){
            if(!isVis[i]){
                cycle = max(cycle, f(i, isVis, nbr));
            }
        }
        return cycle;
    }
};

// floyd's cycle detection algorithm
class Solution {
public:
    int longestCycle(vector<int>& nbr) {
        int n = nbr.size();
        vector<bool> isVis(n, false);
        int res = -1;
        for(int i = 0; i < n; i++){
            if(!isVis[i]){
                int turtle = i, hare = i;
                while(hare != -1 && nbr[hare] != -1){
                    turtle = nbr[turtle];
                    hare = nbr[nbr[hare]];
                    if(isVis[turtle]) break;
                    isVis[turtle] = true;
                    if(hare == turtle){
                        int cycle = 0;
                        do{
                            turtle = nbr[turtle];
                            isVis[turtle] = true;
                            cycle++;
                        } while(turtle != hare);
                        res = max(res, cycle);
                        break;
                    }    
                } 
            }
        }
        return res;
    }
};