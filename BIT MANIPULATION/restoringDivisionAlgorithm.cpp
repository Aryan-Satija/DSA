// LEETCODE -> Divide Two Integers 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        // RESTORING DIVISION ALGORITHM
        long long int a = 0, q = 0;
        bool isNeg = ((dividend < 0)^(divisor < 0));
        dividend = abs(dividend); divisor = abs(divisor);
        for(int i = 31; i >= 0; i--){
            a = (dividend&(1 << i)) ? 2*a + 1 : 2*a;
            if(a - divisor >= 0){
                a = a - divisor;
                q = 2*q + 1;
            } 
            else
                q = 2*q;
        }
        return isNeg ? -1*q : q;
    }
};