// LEETCODE -> Largest Color Value in a Directed Graph
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> isVisited, isPathVisited;
    bool dfs(int node, string &colors, vector<vector<int>> &adjacencyList, vector<vector<int>> &dp){
        if(isVisited[node]) return isPathVisited[node] == false;
        isVisited[node] = true;
        isPathVisited[node] = true;
        for(auto child : adjacencyList[node]){
            if(!dfs(child, colors, adjacencyList, dp)) return false; 
            for(int i = 0; i < 26; i++) dp[node][i] = max(dp[node][i], dp[child][i]);
        }
        dp[node][colors[node]-'a']++;
        isPathVisited[node] = false;
        return true;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> dp(colors.size(), vector<int>(26, 0));
        vector<vector<int>> adjacencyList(colors.size());
        for(auto edge : edges) adjacencyList[edge[0]].push_back(edge[1]);
        isVisited.resize(colors.size(), false); 
        isPathVisited.resize(colors.size(), false);
        for(int i = 0; i < colors.size(); i++){
            if(!dfs(i, colors, adjacencyList, dp)) return -1;
        }
        int res = 0, curr_max = 0;
        for(auto arr : dp){
            curr_max = 0;
            for(int i = 0; i < 26; i++)
                curr_max = max(curr_max, arr[i]);
            res = max(res, curr_max);
        }
        return res;
    }
};