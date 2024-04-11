// CODING NINJAS -> Longest Subarray With Sum K (EASY)
#include <bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size(), s = 0, e = 0, len = 0;
    long long sum = 0;
    while(e <= n)
    {
        if(sum < k)
        {
            if(e == n)
                return len;
            sum += a[e++]; 
        }
        else if(sum == k)
        {
            len = max(len, (e - s));
            if(e == n)
                return len;
            sum += a[e++];
        }
        else
            sum -= a[s++]; 
    }
}