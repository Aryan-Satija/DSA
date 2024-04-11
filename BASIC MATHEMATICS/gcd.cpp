// naive approach
#include <bits/stdc++.h>
using namespace std;
int calcGCD(int n, int m){
    int x = min(n, m);
    while(x > 0){
        if(n%x == 0 and m%x == 0)
            return x;
        x--;
    }
}
// euclidean algorithm
int calcGCD2(int n, int m){
    if(n == m)
        return n;
    return n > m ? calcGCD2(n - m, m) : calcGCD2(n, m- n);
}

int calcGCD3(int n, int m){
    if(m == 0)
        return n;
    return calcGCD3(m, n%m);
}