// LEETCODE -> Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) sum += num;
        if(sum%2 != 0) return false;
        vector<vector<int>> dp(nums.size(),  vector<int>((sum/2)+1, 0));
        if(nums[0] <= (sum/2))
            dp[0][nums[0]] = true;
        dp[0][0] = true;
        for(int index = 1; index < nums.size(); index++){
            for(int target = 0; target <= sum/2; target++){
                if(nums[index] > target)
                    dp[index][target] = dp[index-1][target];
                else dp[index][target] = (dp[index-1][target-nums[index]] or dp[index-1][target]);
            }
        }
        return dp[nums.size()-1][sum/2];
    }
};