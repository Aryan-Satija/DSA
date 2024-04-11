// 

#include <bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2){
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    int res = 0;
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(str1[i] == str2[j]) dp[i][j] = 1 + dp[i+1][j+1];
            else dp[i][j] = 0;
            res = max(res, dp[i][j]);
        }
    }
    
    return res;
}