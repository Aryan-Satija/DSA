// coding ninjas -> Subset Sum Equal To K
#include <bits/stdc++.h> 
using namespace std;
bool f(int index, int sum, vector<int> &arr, vector<vector<int>> &dp){
    if(index == arr.size()) return sum == 0;
    if(sum < 0) return false;
    if(dp[index][sum] != -1) return dp[index][sum];
    return dp[index][sum] = f(index+1, sum-arr[index], arr, dp) or f(index+1, sum, arr, dp);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(0, k, arr, dp);
}