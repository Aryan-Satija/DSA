// LEETCODE -> BUY AND SELL STOCKS-1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, sell = INT_MIN;
        for(int i = (prices.size() - 1); i >= 0; i--){
            sell = max(sell, prices[i]);
            res = max(res, sell - prices[i]);
        }
        return res;
    }
};