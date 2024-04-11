// LEETCODE -> COUNT PRIMES
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1)
            return 0;
        vector<bool> seive(n, true);
        seive[0] = false, seive[1] = false;
        int cnt = 0;
        for(long long int i = 2; i < n; i++){
            if(seive[i]){
                cnt++;
                for(long long int j = (i*i); j < n; j += i)
                    seive[j] = false;
            }
        }
        return cnt;
    }
};