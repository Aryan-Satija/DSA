// LEETCODE => Maximum Profit in Job Scheduling
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nextJob(int low, int high, int &num, vector<vector<int>> &jobs){
        int mid;
        while(low < high){
            mid = (low + high)/2;
            if(jobs[mid][0] >= num) high = mid;
            else low = mid+1;
        }
        return high;
    }
    int f(int i, vector<vector<int>> &jobs, vector<int> &dp){
        if(i == jobs.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ni = nextJob(i+1, jobs.size(), jobs[i][1], jobs);
        return dp[i] = max(jobs[i][2] + f(ni, jobs, dp), f(i+1, jobs, dp));
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        jobs.push_back({0, 0, 0});
        for(int i = 0; i < profit.size(); i++) jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        vector<int> dp(jobs.size(), -1);
        return f(0, jobs, dp);
    }
};