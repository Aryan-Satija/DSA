// LEETCODE -> MAXIMUM OR
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long int>postfixOr(n+1, 0);
        for(int i = n-1; i >= 0; i--)
            postfixOr[i] = (nums[i]|postfixOr[i+1]);
        long long int prefix = 0, res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, prefix | ((1LL*nums[i]) << k) | postfixOr[i+1]);
            prefix = (prefix | nums[i]);
        }
        return res;
    }
};