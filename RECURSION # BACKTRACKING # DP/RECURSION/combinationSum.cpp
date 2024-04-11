// LEETCODE -> COMBINATION SUM I
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(vector<int> &candidates, int index, int target, vector<vector<int>> &res, vector<int> &combination){
        if(target == 0){
            res.push_back(combination);
            return;
        }
        if(target < 0 or index == candidates.size()) return;
        for(int i = index; i < candidates.size(); i++){
            combination.push_back(candidates[i]);
            f(candidates, i, target-candidates[i], res, combination);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        f(candidates, 0, target, res, combination);
        return res;
    }
};