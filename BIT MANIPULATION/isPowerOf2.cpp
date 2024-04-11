// LEETCODE -> IS POWER OF 2
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        int cnt = 0;
        for(int i = 0; i < 32; i++){
            if((n & (1 << i)) != 0){
                if(++cnt > 1)
                    return false;
            }
        }
        return true;
    }
};
// aliter
// brian kernighan algorithm
class Solution2 {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        return (n&(n-1))== 0 ? true : false;
    }
};