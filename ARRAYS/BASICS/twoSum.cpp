#include <bits/stdc++.h>
using namespace std;
string TwoSum(int n, vector<int> nums, int target)
{
    sort(nums.begin(), nums.end());
    int s = 0, e = (n - 1);
    while(s < e)
    {
        if((nums[s] + nums[e]) > target) e--;
        else if((nums[s] + nums[e]) < target) s++;
        else
        {
            return "YES";
        }
    }
    return "NO";
}
