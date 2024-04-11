// Kth Missing Positive Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if((arr.back() - arr.size()) < k) return (arr.size() + k);
        int low = 0, high = arr.size()-1, mid;
        while(low < high){
            mid = (low + high)/2;
            if((arr[mid] - 1 - mid) < k) low = mid + 1;
            else high = mid;
        }
        return (k + high);   
    }
};