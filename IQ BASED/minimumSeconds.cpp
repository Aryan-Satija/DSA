// LEETCODE -> Minimum Seconds to Equalize a Circular Array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        for(int i = 0; i < n; i++) indices[nums[i]].push_back(i);
        int time = INT_MAX;
        for(auto num : nums)
        {
            int m = indices[num].size();
            int currtime = (n - indices[num][m-1] + indices[num][0])/2;
            for(int i = 1; i < m; i++)
                currtime = max(currtime, ((indices[num][i] - indices[num][i-1])/2));
            time = min(time, currtime);
        }
        return time;
    }
};