// Insert Interval
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals)    {
        vector<vector<int>> mergedIntervals;
        int interval_ptr = 0, n = intervals.size();
        while(interval_ptr < n)
        {
            // non-overlapping cases
            if(newIntervals[1] < intervals[interval_ptr][0])
                break;
            else if(newIntervals[0] > intervals[interval_ptr][1])
                mergedIntervals.push_back(intervals[interval_ptr]);
            // overlapping case
            else{
                newIntervals[0] = min(newIntervals[0], intervals[interval_ptr][0]);
                newIntervals[1] = max(newIntervals[1], intervals[interval_ptr][1]);
            }
            interval_ptr++;

        }
        mergedIntervals.push_back(newIntervals);
        while(interval_ptr < n)
        {
            mergedIntervals.push_back(intervals[interval_ptr]);
            interval_ptr++;
        }
        return mergedIntervals;
    }
};