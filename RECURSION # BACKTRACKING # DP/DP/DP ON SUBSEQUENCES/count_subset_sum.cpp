#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	dp[n-1][0] = 1;
	if(arr[n-1] <= k)
		dp[n-1][arr[n-1]] = 1;
	for(int i = (n-2); i >= 0; i--){
		for(int j = 0; j <= k; j++){
			dp[i][j] = dp[i+1][j];
			if(j >= arr[i]) dp[i][j] = (dp[i][j] + dp[i+1][j-arr[i]])%mod;
		}
	}
	return dp[0][k];
}
