// CODING NINJAS -> Subarrays with Sum ‘k'
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> subarraysWithSumK(vector<int> a, long long k) {
    int start = 0, end = 0, n = a.size();
    long long sum = 0;
    vector<vector<int>> res;
    while(start < n){
        if(sum == k){
            vector<int> row;
            for(int i = start; i < end; i++)   row.push_back(a[i]);
            res.push_back(row);
            sum -= a[start++];
        }
        else if(sum < k){
            if(end == n)
                break;
            sum += a[end++];
        }
        else
            sum -= a[start++];
    }
    return res;
}