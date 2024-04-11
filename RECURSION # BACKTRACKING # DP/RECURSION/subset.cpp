// LEETCODE -> SUBSETS - II
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(int index, vector<int> &nums, vector<int> &subset, vector<vector<int>> &res){
        res.push_back(subset);
        if(index == nums.size())
            return;
        int last = 1e9;
        for(int i = index; i < nums.size(); i++){
            if(last != nums[i]){
                subset.push_back(nums[i]);
                f(i + 1, nums, subset, res);
                subset.pop_back();
                last = nums[i];
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        f(0, nums, subset, res);
        return res;
    }
};