// Find the Smallest Divisor Given a Threshold
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()), mid, sum;
        while(low < high){
            mid = (low + high)/2;
            sum = 0;         
            for(auto num : nums)
                sum += ((num + mid - 1)/mid);
            
            if(sum <= threshold) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};