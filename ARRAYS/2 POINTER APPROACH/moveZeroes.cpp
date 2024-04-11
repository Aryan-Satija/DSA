// LEETCODE -> MOVE ZEROES
#include <bits/stdc++.h>
using namespace std;
void moveZeroes1(vector<int>& nums) {
    int s = 0, e = 0;
    int n = nums.size();
    while(e < n)
    {
        if(nums[e] == 0)
            e++;
        else
        {
            if(s < e)
            {
                if(nums[s] == 0)
                {
                    swap(nums[s], nums[e]);
                    s++;
                    e++;
                }
                else
                    s++;
            }
            else
            {
                s++;
                e++;
            }
        }
    }
}

// --------------------------------------------------------------------------------
// OPTIMISED

void moveZeroes2(vector<int>& nums) {
    int s = 0, e = 0;
    int n = nums.size();
    while(e < n)
    {
        if(nums[e] != 0)
            swap(nums[s++], nums[e]);
        e++;
    }
}