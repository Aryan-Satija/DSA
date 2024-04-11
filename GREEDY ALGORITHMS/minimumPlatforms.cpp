// CODING NINJAS -> Minimum Number of Platforms
#include <bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);

    int ptr1 = 0, ptr2 = 0, platforms = 0, minPlatforms = 0;
    while(ptr1 < n)
    {
        if(at[ptr1] <= dt[ptr2])
        {
            minPlatforms = max(++platforms, minPlatforms);
            ptr1++;
        }
        else
        {
            platforms--;
            ptr2++;
        }
    }
    return minPlatforms;
}
