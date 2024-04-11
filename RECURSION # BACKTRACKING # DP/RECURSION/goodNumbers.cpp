// Count Good Numbers
#include <bits/stdc++.h>
using namespace std;
// o(n)
#define mod 1000000007
class Solution {
public:
    long long int countGoodNumbers(long long n) {
        if(n == 1)
            return 5;
        return (n&1) ? (5*(countGoodNumbers(n-1)%mod))%mod : (4*(countGoodNumbers(n-1)%mod))%mod;
    }
};

// O(logn)
class Solution2 {
public:
    long long int pow(long long int base, long long int power){
        if(power == 0)
            return 1;
        long long int x = pow(base, power/2);
        long long int res = (x*x)%mod;
        return power%2 == 0 ? res : (base*res)%mod;
    }
    long long int countGoodNumbers(long long n) {
        if(n%2 == 0)
            return pow(20, n/2);
        return (5*pow(20, n/2))%mod;
    }
};