#include <bits/stdc++.h>
using namespace std;
unsigned long long power(unsigned long long x, int y, int p)
{
    unsigned long long res = 1; 
    x = x % p;
    while (y > 0) 
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
unsigned long long modInverse(unsigned long long n, int p)
{
    // (n^-1)%p = n^(p-2) // fermat's little 
    return power(n, p - 2, p);
} 