// LEETCODE -> SORTING 3 GROUPS
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int index, int prev, vector<int> nums, vector<vector<int>> &dp){
        if(index == nums.size())
            return 0;
        if(dp[index][prev] != -1)
            return dp[index][prev];
        int res = INT_MAX;
        for(int i = prev; i <= 3; i++){
            if(i == nums[index])
                res = min(res, f(index + 1, i, nums, dp));
            else
                res = min(res, 1 + f(index + 1, i, nums, dp));
        }
        return dp[index][prev] = res;
    }
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(4, -1));
        return f(0, 1, nums, dp);
    }
};