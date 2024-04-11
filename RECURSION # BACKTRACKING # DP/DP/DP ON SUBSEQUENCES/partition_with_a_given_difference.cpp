// CODE360
// MEDIUM

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int f(vector<int> &a, int tar){
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    dp[n-1][0]++;
    if(a[n-1] <= tar) dp[n-1][a[n-1]]++;

    for(int i = (n-2); i >= 0; i--){
        for(int j = 0; j <= tar; j++){
            dp[i][j] = dp[i+1][j];
            if(j >= a[i]) dp[i][j] = (dp[i][j] + dp[i+1][j - a[i]])%mod;
        }
    }

    return dp[0][tar];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int s = 0;
    for(auto num : arr) s += num;
    if((s + d)&1) return 0;
    int tar = (s+d)/2;

    return f(arr, tar);

}


