// LEETCODE -> SEARCH INSERT POSITION
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int res = nums.size();
        int low = 0, high  = nums.size()-1, mid;
        while(low <= high){
            mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) res = mid, high = mid-1;
            else low = mid + 1;
        }
        return res;
    }
};
