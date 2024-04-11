// LEETCODE
// Longest Common Subsequence

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2){
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i1 = n1-1; i1 >= 0; i1--){
            for(int i2 = n2-1; i2 >= 0; i2--){
                if(text1[i1] == text2[i2]) dp[i1][i2] = 1 + dp[i1 + 1][i2 + 1];
                else dp[i1][i2] = max(dp[i1+1][i2], dp[i1][i2+1]);
            }
        }

        return dp[0][0];
    }
};