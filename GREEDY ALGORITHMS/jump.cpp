// LEETCODE -> Jump Game
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    // Dynamic Programming Approach
    bool f(int index, vector<int> nums, vector<int> &dp){
        if(index >= (nums.size() - 1))
            return true;
        if(dp[index] != -1)
            return dp[index];
        int steps = nums[index];
        for(int i = 1; i <= steps; i++)
        {
            if(f(index + i, nums, dp))
                return dp[index] = 1;
        }
        return dp[index] = 0;
    }
    bool dpApproach(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(0, nums, dp);
    }
    // Greedy Approach
    bool greedyApproach(vector<int>& nums) 
    {
        int n = nums.size();
        int high = 0, low = 0;
        for(; low < n; low++)
        {
            if(high < low)
                return false;
            high = max(low + nums[low], high);
        }
        return true;
    }
};