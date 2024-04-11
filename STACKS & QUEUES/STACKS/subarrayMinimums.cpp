// Sum of Subarray Minimums
#include <bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int>& a) 
{
    int n = a.size();
    stack<pair<int, int>> st1;
    vector<int> NSE(n);
    for(int i = (n -1); i >= 0; i--)
    {
        while(!st1.empty() and st1.top().first > a[i])
            st1.pop();
        NSE[i] = st1.empty() ? n : st1.top().second;
        st1.push({a[i], i});
    }
    stack<pair<int, int>> st2;
    vector<int> PSE(n);
    for(int i = 0; i < n; i++)
    {
        while(!st2.empty() and st2.top().first >= a[i])
            st2.pop();
        PSE[i] = st2.empty() ? -1 : st2.top().second;
        st2.push({a[i], i});
    }
    long long int mod = 1e9 + 7;
    long long int ans = 0;
    for(int i = 0; i < n; i++)
    {
        long long int m = (i - PSE[i]);
        long long int n = (NSE[i] - i);
        long long int total_subarrays = m*n;
        ans = (ans + a[i]*total_subarrays)%mod;
    }
    return ans;
}