#include <bits/stdc++.h>
using namespace std;
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int secondMax = INT_MIN, max = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= max)
        {
            secondMax = max;
            max = a[i];
        }
        else if(a[i] > secondMax)
            secondMax = a[i];
    }
    
    int secondMin = INT_MAX, min = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(a[i] <= min)
        {
            secondMin = min;
            min = a[i];
        }
        else if(a[i] < secondMin)
            secondMin = a[i];
    }
    return {secondMax, secondMin};
}
