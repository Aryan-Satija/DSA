// SCHEDULING ALGORITHM
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meetings;
        for(int i = 0; i < n; i++){
            meetings.push_back({end[i], start[i]});
        }
        sort(meetings.begin(), meetings.end());
        int cnt = 0, endTime = INT_MIN;
        for(auto meet : meetings)
        {
            int s = meet.second;
            int e = meet.first;
            if(s > endTime)
            {
                cnt++;
                endTime = e;
            }
        }
        return cnt;
    }
};