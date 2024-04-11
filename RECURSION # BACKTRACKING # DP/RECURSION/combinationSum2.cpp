// LEETCODE -> COMBINATION SUM II
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
            if(i == index or candidates[i] != candidates[i - 1]){
                combination.push_back(candidates[i]);
                f(candidates, i + 1, target-candidates[i], res, combination);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        f(candidates, 0, target, res, combination);
        return res;
    }
};
