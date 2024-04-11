// LEETCODE -> COMBINATION SUM III
// DON'T USE INCLUDE - EXCLUDE APPROACH AS TIME COMPLEXITY REMAINS SAME
// BUT HEIGHT OF THE RECURSIVE TREE INCREASES 
// SO THE STACK SPACE CONSUMED ALSO INCREASES!
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(int target, int in, int k, vector<int> &helper, vector<vector<int>> &res){
        if(k == 0 and target == 0){
            res.push_back(helper);
            return;
        }
        if(k < 0 or target < 0)
            return;
        for(int i = in; i <= 9; i++){
            helper.push_back(i);
            f(target - i, i + 1, k - 1, helper, res);
            helper.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> helper;
        f(n, 1, k, helper, res);
        return res;
    }
};