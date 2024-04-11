// LEETCODE -> Count All Subarrays With Given Sum
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int sum = 0;
        int res = 0;
        freq[0]++;
        for(auto num : nums){
            sum += num;
            res += freq[sum-k];
            freq[sum]++;
        }
        return res;
    }
};