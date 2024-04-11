#include <bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
int ncr(int n, int r)
{
    r = min(n-r, r); // nCr = nC(n-r)
    int res = 1;
    for(int i = 1; i <= r; i++)
        res = (res*(n - i + 1))/i;
    return res;
}
