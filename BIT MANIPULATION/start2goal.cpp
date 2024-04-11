// LEETCODE -> Minimum Bit Flips to Convert Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        while(goal > 0 or start > 0)   
            cnt += ((goal&1)^(start&1)), goal >>= 1, start >>= 1;
        return cnt;
    }
};