#include <bits/stdc++.h>
using namespace std;
int isSorted(int n, vector<int> a) {
    for(int i = 1; i < n; i++)
    {
        if(a[i] < a[i - 1])
            return false;
    }
    return true;
}
