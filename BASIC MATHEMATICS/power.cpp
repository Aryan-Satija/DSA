#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double myPow(double x, long n) {
        if(n < 0) 
            n = abs(n), x = 1/x;
        double res = 1;
        while(n > 0){
            if(n&1) res = res*x;
            x = x*x;
            n = n/2; 
        }
        return res;
    }
};

// follow up : try to find mth root a number n;
// use newton raphson method; 
