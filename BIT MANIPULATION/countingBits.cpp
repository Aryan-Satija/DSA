// LEETCODE -> Counting Bits
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // O(nlogn)
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for(int i = 0; i <= n; i++){
            int bits = 0, num = i;
            while(num > 0){
                num = (num&(num - 1));
                bits++;
            }
            res[i] = bits;
        }
        return res;
    }
    // O(n)
    vector<int> countBits2(int n) {
        vector<int> res(n + 1);
        res[0] = 0;
        for(int i = 0; i <= n; i++){
            res[i] = (i&1) ? (res[i/2] + 1) : res[i/2];
        }
        return res;
    }
};