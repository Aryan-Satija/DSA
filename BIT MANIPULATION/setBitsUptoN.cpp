// CODING NINJAS -> Count total set bits 
#include <bits/stdc++.h>
using namespace std;
int countSetBits(int N)
{
    long long int res = 0;
    for(long long int i = 1; i < 32; i++) 
        res = res + ((N + 1)/(1 << i))*(1 << (i - 1)) + max(0,(((N + 1)%(1 << i)) - (1 << (i - 1))));
    return res;
}