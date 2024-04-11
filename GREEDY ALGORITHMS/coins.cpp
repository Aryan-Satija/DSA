#include <bits/stdc++.h>
using namespace std;
int MinimumCoins(int n)
{
    int coins = 0;
    int denominations[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    for(int i = 0; i <= 8 and n > 0; i++)
    {
        coins += n/denominations[i];
        n = n%denominations[i];
    }
    return coins;
}