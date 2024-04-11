// LEETCODE -> Find the City With the Smallest Number of Neighbors at a Threshold Distance
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        
        for(int i = 0; i < n; i++)
            mat[i][i] = 0;
        
        for(auto edge : edges){
            mat[edge[0]][edge[1]] = edge[2];
            mat[edge[1]][edge[0]] = edge[2];
        } 

        // floyd warshall algorithms 
        // TC : (O(V^3))
        
        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++)
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }

        int res, res_cnt = INT_MAX, city_cnt;
        
        for(int i = n-1; i >= 0; i--){
            city_cnt = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] <= distanceThreshold) city_cnt++;
            }
            if(city_cnt < res_cnt){
                res_cnt = city_cnt;
                res = i;
            }
        } 

        return res;
    }
};