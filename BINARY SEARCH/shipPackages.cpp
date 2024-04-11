#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;
        for(auto weight : weights){
            high += weight;
            low = max(weight, low);
        }
        while(low < high){
            int mid = (low + high)/2;
            int req_days = 1, load = 0;
            for(auto weight : weights){
                if(load + weight <= mid) load += weight;
                else{
                    load = weight;
                    req_days++;
                }
            }
            if(req_days <= days) high = mid;
            else low = mid + 1;
        }
        return high;
    }
};