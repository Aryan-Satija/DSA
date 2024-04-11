// LEETCODE -> Power of Four
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0 || (n&(n-1)) != 0)
            return false; // n is not a power of 2 and hence can't be a power of 4 as well
        return (n%3 == 1); 
    }
};