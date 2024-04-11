// LEETCODE -> frog jump 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool f(int jump, int start, int end, vector<unordered_map<int, bool>> &dp, unordered_map<int, bool> &isPresent){
        if(!isPresent[start])
            return false;
        if(start == end)
            return true;
        if(dp[jump].find(start) != dp[jump].end())
            return dp[jump][start];
        if(jump == 1)
            return dp[jump][start] = (f(1, start + 1, end, dp, isPresent) or f(2, start + 2, end, dp, isPresent));
        return dp[jump][start] = (f(jump - 1, start + jump - 1, end, dp, isPresent) or f(jump, start + jump, end, dp, isPresent) or f(jump + 1, start + jump + 1, end, dp, isPresent));
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int, bool> isPresent;
        for(auto num : stones)
            isPresent[num] = true;
        vector<unordered_map<int, bool>> dp(stones.size() + 1);
        return f(1, 1, stones[stones.size() - 1], dp, isPresent);
    }
};
