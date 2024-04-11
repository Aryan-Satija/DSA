// LEETCODE -> Frequency of the Most Frequent Element
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long int res = 0, low = 0, high = 0;
        long long int sum = nums[high];
        while(high < nums.size()){
            if(nums[high]*(high - low + 1) <= sum + k){
                res = max(res, high - low + 1);
                high++;
                if(high < nums.size())
                    sum += nums[high];
            }
            else sum -= nums[low++];
        }
        return res;
    }
};