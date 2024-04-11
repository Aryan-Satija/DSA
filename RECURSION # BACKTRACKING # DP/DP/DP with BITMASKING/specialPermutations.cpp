// LEETCODE -> SPECIAL PERMUTATIONS
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    int n;
    int dfs(int last, vector<int> &nums, int bitmask, vector<vector<int>> &dp){
        if(bitmask == ((1<<n) - 1)) return 1;
        if(dp[last][bitmask] != -1) return dp[last][bitmask];
        int res = 0;
        for(int i = 1; i < n; i++){
            if(!(bitmask&(1<<i))){
                if((nums[i]%nums[last] == 0) || (nums[last]%nums[i] == 0))
                    res = (res + dfs(i, nums, (bitmask|(1<<i)), dp))%mod;
            }
        }
        return dp[last][bitmask] = res;
    }
    int specialPerm(vector<int>& nums) {
        n = nums.size()+1;
        vector<int> copy_nums; copy_nums.push_back(1);
        for(auto num : nums) copy_nums.push_back(num);
        vector<vector<int>> dp(n+1, vector<int>(1<<n, -1));
        return dfs(0, copy_nums, 1, dp); 
    }
};