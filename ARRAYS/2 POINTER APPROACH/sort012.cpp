// LEETCODE -> SORT COLORS
#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int>& nums) {
    int n = nums.size();
    // MOVING 0s TO END...
    int s = n - 1, e = n - 1;
    while(e >= 0)
    {
        if(nums[e] != 0)
            swap(nums[s--], nums[e]);
        e--;
    }
    // MOVING 2s TO END...
    s = 0, e = 0;
    while(e < n)
    {
        if(nums[e] != 2)
            swap(nums[s++], nums[e]);
        e++;
    }
}
void sortColors2(vector<int>& nums) {
    // DUTCH NATIONAL FLAG ALGORITHM ...
    // 3 - POINTER APPROACH
    int n = nums.size();
    int s = 0, m = 0, e = (n - 1);
    while(m <= e)
    {
        if(nums[m] == 0)
            swap(nums[m++], nums[s++]);
        else if(nums[m] == 1)
            m++;
        else
            swap(nums[m], nums[e--]);
    }
