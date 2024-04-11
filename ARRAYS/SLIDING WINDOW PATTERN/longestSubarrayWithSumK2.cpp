// LEETCODE -> Subarray Sum Equals K
#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int>& nums, int k) 
{
    unordered_map<int, int> prefixSum;
    prefixSum[0]++;
    int sum = 0, cnt = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if(prefixSum.find(sum - k) != prefixSum.end())
            cnt = cnt + prefixSum[sum - k];
        prefixSum[sum]++;
    }
    return cnt;
}