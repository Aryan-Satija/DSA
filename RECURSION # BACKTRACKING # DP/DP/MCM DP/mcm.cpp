// CODING NINJAS -> Matrix Chain Multiplication
#include <bits/stdc++.h>
using namespace std;
int f(int *arr, int st, int end, vector<vector<int>> &dp){
    if(st == end) return 0;
    if(dp[st][end] != -1) return dp[st][end];
    int res = INT_MAX;
    for(int md = st; md < end; md++)
        res = min(res, ((arr[st-1]*arr[md]*arr[end]) + f(arr, st, md, dp) + f(arr, md + 1, end, dp)));
    return dp[st][end] = res;
}
int matrixChainMultiplication(int* arr, int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return f(arr, 1, n, dp);
}