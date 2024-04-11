#include <bits/stdc++.h>
using namespace std;
bool palindrome(int n)
{
    int num = n, rev = 0;
    while(n > 0){
        rev = rev*10 + n%10;
        n /= 10;
    }
    return num == rev;
}