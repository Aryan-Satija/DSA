// CODING NINJAS -> Square Root of a number
#include <bits/stdc++.h> 
using namespace std;
int floorSqrt(long long int N)
{
    if(N == 0) return 0;
    long long int res = 1;
    long long int low = 1, high = N;
    while(low <= high){
        long long int mid = (low + (high - low)/2);
        if(mid > N/mid) high = mid-1;
        else res = mid, low = mid + 1;
    }
    return res;
}