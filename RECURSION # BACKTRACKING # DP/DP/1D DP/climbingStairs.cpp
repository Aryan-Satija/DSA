// LEETCODE -> Climbing Stairs
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[n] = 1;
        dp[n-1] = 1;
        for(int i = (n-2); i >= 0; i--)
            dp[i] = (dp[i + 1] + dp[i + 2]);
        return dp[0];
    }
};
