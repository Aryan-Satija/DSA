// LEETCODE -> Max Consecutive Ones
#include <bits/stdc++.h> 
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0;
    int len = 0;
    for(auto bit : nums)
    {
        if(bit)
            len++;
        else
        {
            res = max(res, len);
            len = 0;
        }
    }
    return max(res, len);
}