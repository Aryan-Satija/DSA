// KADANE'S ALGORITHM
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, max_sum = 0, n = nums.size(), max_digit = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            max_sum = max(max_sum, sum + nums[i]);
            sum = max(sum + nums[i], 0);
            max_digit = max(max_digit, nums[i]);
        }
        return max_sum == 0 ? max_digit : max_sum;
    }
};