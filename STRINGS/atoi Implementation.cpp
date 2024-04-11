#include <bits/stdc++.h>
using namespace std;
int myAtoi(string a) {
    int index = 0;
    while(a[index] == ' ')
        index++; 
    bool isNegative = false;
    if(a[index] == '-'){
        index++;
        isNegative = true;
    }
    else if(a[index] == '+')
        index++;
    long long int res = 0, uprBound = INT_MAX, lwrBound = INT_MIN;
    while(index < a.length()){
        if(a[index] >= '0' and a[index] <= '9'){
            res = (10*res + (a[index] - '0'));
            if(isNegative){
                if(res >= (-1LL*lwrBound)) return (int)lwrBound;
            } 
            else{
                if(res >= (uprBound)) return (int)uprBound;
            }
        }
        else
            return isNegative ? -1*(int)res : (int)res;
        index++;
    }
    return isNegative ? -1*(int)res : (int)res;
}