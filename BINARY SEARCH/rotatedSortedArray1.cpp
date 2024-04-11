// LEETCODE -> Search in Rotated Sorted Array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] <= nums[n-1]){
                if(target > nums[n-1])
                    high = mid-1;
                else{
                    if(target > nums[mid])
                        low = mid+1;
                    else high = mid-1;
                }
            }
            else{
                if(target > nums[n-1]){
                    if(target > nums[mid])
                        low = mid+1;
                    else high = mid-1;
                }
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
};