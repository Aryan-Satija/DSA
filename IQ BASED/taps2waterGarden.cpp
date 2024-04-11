// LEETCODE -> Minimum Number of Taps to Open to Water a Garden
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int lastLwrBnd = 0, currentUprBnd = 0, taps = 0;
        while(currentUprBnd < n){
            for(int i = 0; i < ranges.size(); i++){
                if(i - ranges[i] <= lastLwrBnd)
                    currentUprBnd = max(currentUprBnd, i + ranges[i]);
            }
            if(currentUprBnd == lastLwrBnd)
                return -1;
            taps++;
            lastLwrBnd = currentUprBnd;
        }
        return taps;
    }
};