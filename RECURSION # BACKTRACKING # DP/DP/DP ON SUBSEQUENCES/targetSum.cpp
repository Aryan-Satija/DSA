// LEETCODE -> TARGET SUM
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findWays(vector<int> &num, int target)
    {   
        int n = num.size();
        vector<int> curr(target + 1, 0);
        curr[0] = 1;
        vector<int> temp(target + 1);

        for(int index = n-1; index >= 0; index--)
        {
            for(int tar = 0; tar <= target; tar++)
            {
                if(tar >= num[index])
                    temp[tar] = (curr[tar - num[index]] + curr[tar]);
                else
                    temp[tar] = curr[tar];
            }
            curr = temp;
        }
        return curr[target];
    }
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int sum = 0;
        for(auto num : arr) sum += num;
        if(sum < d or (d + sum)&1)
            return 0;
        int target = (d + sum)/2;
        return findWays(arr, target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return  countPartitions(nums.size(), abs(target), nums);
    }
};