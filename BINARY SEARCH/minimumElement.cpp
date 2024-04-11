// Find Minimum in Rotated Sorted Array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n-1] || n == 1) return nums[0];
        int low = 0, high = n-1, res = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > nums[0] || mid == 0) low = mid + 1;
            else {
                res = nums[mid];
                high = mid - 1;
            }
        }
        return res;
    }
};