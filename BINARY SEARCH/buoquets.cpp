// LEETCODE -> Minimum Number of Days to Make m Bouquets
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((1LL*m*k) > 1LL*(bloomDay.size())) return -1;
        int low = 1e9, high = 0;
        for(auto day : bloomDay) low = min(low, day), high = max(high, day); 
        while(low < high){
            int mid = (low + high)/2;
            int bouquets = 0;
            for(auto day : bloomDay){
                if(mid >= day) bouquets++;
                else bouquets -= (bouquets%k);
            }
            bouquets /= k;
            if(bouquets >= m) high = mid;
            else low = mid + 1;
        }
        return high;
    }
};