// LEETCODE -> BUY AND SELL STOCKS-2
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        for(int index = prices.size()-1; index >= 0; index--){
            dp[index][1] = max(dp[index+1][0]-prices[index], dp[index+1][1]);
            dp[index][0] = max(dp[index+1][1]+prices[index], dp[index+1][0]);
        }
        return dp[0][1];
    }
};