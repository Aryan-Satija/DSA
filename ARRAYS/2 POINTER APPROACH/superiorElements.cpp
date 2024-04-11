#include <bits/stdc++.h>
using namespace std;
vector<int> superiorElements(vector<int>&a) {
    int n = a.size();
    int largestElem = INT_MIN;
    vector<int> res;
    for(int i = (n - 1); i >= 0; i--)
    {
        if(a[i] > largestElem)
        {
            res.push_back(i);
            largestElem = a[i];
        }
    }
    reverse(res.begin(), res.end());
    return res;
}