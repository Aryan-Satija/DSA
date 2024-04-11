// CODING NINJAS -> One Odd Occurring
#include <bits/stdc++.h>
using namespace std;
int missingNumber(int n, vector<int> &arr){
    int res = 0;
    for(auto num : arr)
        res = res^num;
    return res;
}