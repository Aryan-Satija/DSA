// CODING NINJAS -> NEXT GREATER PERMUTATION
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterPermutation(vector<int> &nums) {
    int n = nums.size(), i = (n - 1);
    while(i > 0 and nums[i-1] >= nums[i])
        i--;   
    if(i == 0)
        sort(nums.begin(), nums.end());
    else
    {
        int j = i;
        while(j < n and nums[i - 1] < nums[j])
            j++;
        swap(nums[i - 1], nums[j - 1]);
        int s = i, e = (n - 1);
        while(s < e)
            swap(nums[s++], nums[e--]);
    }    
    return nums;
}

// ----------------------------------------------
vector<int> nextGreaterPermutation2(vector<int> nums) {
    next_permutation(nums.begin(), nums.end());
    return nums;
}