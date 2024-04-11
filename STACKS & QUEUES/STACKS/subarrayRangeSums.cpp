// LEETCODE -> Sum of Subarray Ranges
#include <bits/stdc++.h>
using namespace std;
long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    stack<pair<int, int>> st1, st2;
    vector<int> NGI(n), NSI(n);
    for(int i = (n - 1); i >= 0; i--)
    {
        while(!st1.empty() and st1.top().first >= nums[i])
            st1.pop();
        NSI[i] = st1.empty() ? n : st1.top().second;
        st1.push({nums[i], i});
        while(!st2.empty() and st2.top().first <= nums[i])
            st2.pop();
        NGI[i] = st2.empty() ? n : st2.top().second;
        st2.push({nums[i], i});
    }
    stack<pair<int, int>> st3, st4;
    vector<int> PGI(n), PSI(n);
    for(int i = 0; i < n; i++)
    {
        while(!st3.empty() and st3.top().first > nums[i])
            st3.pop();
        PSI[i] = st3.empty() ? -1 : st3.top().second;
        st3.push({nums[i], i});
        while(!st4.empty() and st4.top().first < nums[i])
            st4.pop();
        PGI[i] = st4.empty() ? -1 : st4.top().second;
        st4.push({nums[i], i});
    }
    long long int sum = 0;
    for(int i = 0; i < n; i++)
    {
        long long int  subarr1 = ((i - PGI[i])*(NGI[i] - i));
        long long int subarr2 = ((i - PSI[i])*(NSI[i] - i));
        sum += ((subarr1 - subarr2)*nums[i]);
    }
    return sum;
}