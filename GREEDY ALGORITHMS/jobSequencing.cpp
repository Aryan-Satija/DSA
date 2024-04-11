// CODING NINJAS -> Job Sequencing Problem
#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> a, vector<int> b)
{
    return a[2] > b[2]; // on the basis of more profit
}
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    sort(jobs.begin(), jobs.end(), cmp);
    int maxDeadLine = INT_MIN;
    for(auto it : jobs)
        maxDeadLine = max(maxDeadLine, it[1]);
    vector<bool> isFree(maxDeadLine, true);
    int cnt = 0, maxProfit = 0;
    for(auto job : jobs)
    {
        int deadline = job[1];
        int profit = job[2];
        for(int i = (deadline - 1); i >= 0; i--)
        {
            if(isFree[i])
            {
                isFree[i] = false;
                cnt++;
                maxProfit += profit;
                break;
            }
        }
    }
    vector<int> ans;
    ans.push_back(cnt); ans.push_back(maxProfit);
    return ans;
}
// CONSIDER THE FOLLOWING TESTCASES:

// JOB-ID   JOB-DEADLINE   JOB-PROFIT

// 1)
// 1 1 40
// 2 1 50
// 3 1 60

// 2)
// 1 2 605
// 2 3 154
// 3 3 383
// 4 2 717
// 5 4 896