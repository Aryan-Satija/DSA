// LEETCODE -> partition array into two subarrays to minimise the difference between them
#include <bits/stdc++.h>
using namespace std;
// meet in the middle algorithm
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int tot = 0;
        for(auto num : nums) tot += num;
        int size = nums.size()/2;
        vector<vector<int>> left(size+1), right(size+1);
        int l, r, sz;
        for(int mask = 0; mask < (1<<size); mask++){
            l = 0, r = 0, sz = 0;
            for(int i = 0; i < size; i++){
                if((mask&(1<<i)) != 0){
                    l += nums[i];
                    r += nums[i+size];
                    sz++;
                }
            }     
            left[sz].push_back(l);
            right[sz].push_back(r);
        }
        int res = INT_MAX;
        for(int i = 0; i <= size; i++) sort(right[i].begin(), right[i].end());
        for(int i = 0; i <= size; i++){
            for(int a : left[i]){
                int b = (tot-(2*a))/2;
                auto itr = lower_bound(right[size-i].begin(), right[size-i].end(), b);
                if(itr!=right[size-i].end())
                    res = min(res, abs(tot-(2*(a + (*itr))))); 
                if(itr!= right[size-i].begin()){
                    itr--;
                    res = min(res, abs(tot-2*(a+(*itr))));
                } 
            }
        }
        return res;
    }
};

// LEETCODE -> closest subsequence sum
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        if(nums.size()&1) nums.push_back(0);
        int size = nums.size()/2;
        vector<int> left, right;
        int lsum, rsum;
        for(int mask = 0; mask < (1<<size); mask++){
            lsum = 0, rsum = 0;
            for(int i = 0; i < size; i++){
                if((mask&(1<<i)) != 0){
                    lsum += nums[i];
                    rsum += nums[size + i];
                }
            }
            left.push_back(lsum);
            right.push_back(rsum);    
        }
        sort(right.begin(), right.end());
        int res = INT_MAX;
        int low, high, mid, tar, b;
        for(int a : left){
            auto itr = lower_bound(right.begin(), right.end(), goal-a);
            if(itr != right.end()) res = min(res, abs(goal - (a + *itr)));
            if(itr != right.begin()) {
                itr--;
                res = min(res, abs(goal - (a + *itr)));
            }
        }
        return res;
    }
};
