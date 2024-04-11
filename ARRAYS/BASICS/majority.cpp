// LEETCODE -> MAJORITY ELEMENT
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int>& nums) {
    // MOORE'S VOTING ALGORITHM
    int cnt = 0, n = nums.size();
    int elem;
    for(int i = 0; i < n; i++)
    {
        if(cnt == 0)
            elem = nums[i];
        
        if(elem == nums[i])
            cnt++;
        else
            cnt--;
    }
    cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == elem)
            cnt++;
    }
    return cnt > n/2 ? elem : -1;
}
