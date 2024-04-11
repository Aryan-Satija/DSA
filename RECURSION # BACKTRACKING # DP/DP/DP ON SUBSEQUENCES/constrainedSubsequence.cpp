// LEETCODE -> Constrained Subsequence Sum
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        int res = -1e9;
        for(int i = 0; i < nums.size(); i++){
            while(!pq.empty() and (i - pq.top().second) > k) pq.pop();
            if(pq.empty()){
                res = max(res, nums[i]);
                if(nums[i] >= 0) pq.push({nums[i], i});
            } 
            else{
                res = max(res, nums[i]+pq.top().first);
                if(nums[i]+pq.top().first >= 0) pq.push({nums[i]+pq.top().first, i});
            }

        }
        return res;
    }
};