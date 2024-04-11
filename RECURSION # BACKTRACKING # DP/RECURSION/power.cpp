// LEETCODE -> Pow(x, n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double f(double x, int n){
        if(n == 0) return 1;
        double temp = myPow(x, n/2);
        return ((n&1) == 0 ? temp*temp : x*temp*temp); 
    }
    double myPow(double x, int n) {
        return (( n < 0 ) ? ( 1.0 / f(x, abs(n)) ) : f(x, n) ); 
    }
};