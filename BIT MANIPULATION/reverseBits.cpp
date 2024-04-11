// CODING NINJAS -> REVERSE BITS
#include <bits/stdc++.h>
using namespace std;
long reverseBits(int n) {
    long long int  res = 0;
    for(long i = 0; i < 32; i++){
        if(n & (1 << i))
            res = (res + ((long long)1 << (31 - i)));
    }
    return res;
}