// LEETCODE -> GRAYCODE
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int> res(1 << n);
        res[0] = 0, res[1] = 1;
        int power = 1;
        for(long long int i = 2; i < (1 << n); i++){
            if((i&(i - 1)) == 0)
                power += 1;
            res[i] = res[(1<<power) - i -1] + (1 << (power - 1));
        }
        return res;
    }
};