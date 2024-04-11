// LEETCODE -> Sum of Imbalance Numbers of All Subarrays
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i++){
            multiset<int> ms;
            ms.insert(nums[i]);
            int prev = 0;
            for(int j = i+1; j < n; j++){
                if(ms.find(nums[j]) == ms.end()){
                    auto itr = ms.insert(nums[j]);
                    auto next_itr = itr;
                    auto prev_itr = itr;

                    next_itr++;
                    prev_itr--;

                    if(itr == ms.begin()){
                        if(*next_itr > nums[j] + 1)
                            prev++;
                    }
                    else if(next_itr == ms.end()){
                        if(nums[j] > *prev_itr + 1)
                            prev++;
                    }
                    else{
                        if(*next_itr > *prev_itr + 1) prev--;
                        if(nums[j] > *prev_itr + 1) prev++;
                        if(*next_itr > nums[j] + 1) prev++;
                    }
                }
                res += prev;
            }
        }
        return res;
    }
};