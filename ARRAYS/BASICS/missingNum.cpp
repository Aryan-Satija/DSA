// LEETCODE -> Missing Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int num = 0, n = nums.size();
        for(int i = 1; i <= n; i++)
            num ^= i;
        for(int i = 0; i < n; i++)
            num = num^nums[i];
        return num;
    }
};