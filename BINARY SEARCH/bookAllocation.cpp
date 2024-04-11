// CODING NINJAS -> Allocate Books
#include <bits/stdc++.h>
using namespace std;
bool isDistributionPossible(vector<int> &arr, int n, int m, int max_pages){
    int grp = 1;
    long long int sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + arr[i] <= max_pages)
            sum += arr[i];
        else sum = arr[i], grp += 1;
    }
    return grp <= m;
}
int findPages(vector<int>& arr, int n, int m) {
    if(n < m) return -1;

    long long int low = 0, high = 0, mid, res;
    for(auto num : arr) high += num, low = num > low ? num : low;

    while(low <= high){
        mid = (low + high)/2;
        if(isDistributionPossible(arr, n, m, mid)) 
            res = mid, high = mid - 1;
        else low = mid + 1; 
    }

    return res;
}


