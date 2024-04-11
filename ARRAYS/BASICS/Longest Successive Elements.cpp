// COING NINJAS -> Longest Successive Elements
#include <bits/stdc++.h>
using namespace std;
int longestSuccessiveElements(vector<int>&a) {
    sort(a.begin(), a.end());
    int n = a.size(), res = 1, len = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] == (a[i-1] + 1))
            res = max(res, ++len);
        else if(a[i] != a[i-1])
            len = 1;
    }
    return res;
}