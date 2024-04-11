// LEETCODE -> Jump Game2
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = 0, jump = 0;
        while(high < (n - 1))
        {
            int newHigh = high;
            while(low <= high)
            {
                newHigh = max(newHigh, nums[low] + low);
                low++;
            }
            high = newHigh;
            jump++;
        }
        return jump;
    }
};