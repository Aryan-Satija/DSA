// LEETCODE -> FIND THE FIRST AND THE LAST OCCURANCE OF AN ELEMENT IN A SORTED ARRAY
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f = -1, l = -1;
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (high + low)/2;
            if(nums[mid] > target) high = mid - 1;
            else if(nums[mid] < target) low = mid + 1;
            else {
                f = mid;
                high = mid - 1;
            }
        }
        low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = (high + low)/2;
            if(nums[mid] > target) high = mid - 1;
            else if(nums[mid] < target) low = mid + 1;
            else {
                l = mid;
                low = mid + 1;
            }
        }
        return {f, l};
    }
};