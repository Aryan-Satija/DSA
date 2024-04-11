// LEETCODE -> Perfect Squares
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 1; i <= n; i++){
            int sq_i = sqrt(i), res = INT_MAX;
            for(int j = 1; j <= sq_i; j++)
                res = min(res, dp[i - (j*j)]);
            dp[i] = 1 + res;
        }
        return dp[n];
    }
};