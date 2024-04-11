// LEETCODE -> 3SUM
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for(int i = 0; i < n and nums[i] <= 0;)
    {
        int num = nums[i], target = -1*nums[i];
        int st = (i + 1), end = (n - 1);
        while(st < end)
        {
            if((nums[st] + nums[end]) < target)
                st++;
            else if((nums[st] + nums[end]) > target)
                end--;
            else
            {
                res.push_back({nums[i], nums[st], nums[end]});
                int j = st;
                for(; j < end and nums[j] == nums[st];) j++;
                st = j;
                int k = end;
                for(; k > st and nums[k] == nums[end];) k--;
                end = k;
            } 
        }
        int l = i;
        while(l < n and nums[l] == nums[i])
            l++;
        i = l;
    }
    return res;
}