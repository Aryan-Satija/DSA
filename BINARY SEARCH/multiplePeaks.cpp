// LEETCODE -> Find Peak Element
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low = 1, high = n-2;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > nums[mid-1]){
                if(nums[mid] > nums[mid+1]) return mid;
                else low = mid + 1;
            }
            else high = mid-1;
        } 
        return -1;
    }
};