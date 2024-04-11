#include <bits/stdc++.h> 
using namespace std;
int largestElement(vector<int> &arr, int n) {
    int res = INT_MIN;
    for(auto num : arr)
        res = max(res, num);
    return res;
}
