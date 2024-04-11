// CODING NINJAS -> COUNT PRIMES
#include <bits/stdc++.h>
using namespace std;
vector<int> countPrimes(int n)
{
    vector<int> res;
    if(n == 0 || n == 1)
        return {};
    vector<bool> seive(n, true);
    seive[0] = false, seive[1] = false;
    int cnt = 0;
    for(long long int i = 2; i < n; i++){
        if(seive[i] and n%i == 0){
            res.push_back(i);
            for(long long int j = (i*i); j < n; j += i)
                seive[j] = false;
        }
    }
    return res;
}