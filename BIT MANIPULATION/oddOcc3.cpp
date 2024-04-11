// LEETCODE -> SINGLE ELEMENT 2
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // counter algorithm
        vector<long long int> bitFrequency(32, 0); // 32nd bit determines sign, hence not considering it
        for(auto num : nums){
            for(long long int i = 0; i < 32; i++)
                bitFrequency[i] += (num & (1 << i));
        }
        long long int res = 0;
        for(long long int i = 0; i < 32; i++)
            res = bitFrequency[i]%3 ? res + (1 << i) : res;
        return res;
    }
};