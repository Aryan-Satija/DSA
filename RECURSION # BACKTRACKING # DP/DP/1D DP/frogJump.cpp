// CODING NINJAS -> Minimal Cost
#include <bits/stdc++.h>
using namespace std;

// recursion
// int f(int index, int k, int n, vector<int> &height){
//     if(index + 1 == n) return 0;
//     int res = INT_MAX;
//     for(int i = 1; i <= k && index + i < n; i++)
//         res = min(res, abs(height[index+i]-height[index])+f(index + i, k, n, height));
//     return res;
// }
// int minimizeCost(int n, int k, vector<int> &height){
//     return f(0, k, n, height);
// }


// memoization 
// int f(int index, int k, int n, vector<int> &height, vector<int> &dp){
//     if(index + 1 == n) return 0;
//     if(dp[index] != -1)
//         return dp[index];
//     int res = INT_MAX;
//     for(int i = 1; i <= k && index + i < n; i++)
//         res = min(res, abs(height[index+i]-height[index])+f(index + i, k, n, height, dp));
//     return dp[index] = res;
// }
// int minimizeCost(int n, int k, vector<int> &height){
//     vector<int> dp(n, -1);
//     return f(0, k, n, height, dp);
// }


// tabulation
int minimizeCost(int n, int k, vector<int> &height){
    vector<int> dp(n, 0);
    for(int j = n - 2; j >= 0; j--){
        int res = INT_MAX;
        for(int i = 1; i <= k && j + i < n; i++)
            res = min(res, abs(height[j+i]-height[j])+dp[j+i]);
        dp[j] = res;
    }
    return dp[0];
}