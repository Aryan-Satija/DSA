// LEETCODE -> MINIMUM PENALTY
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
        int cntY = 0;
        for(auto ch : customers){
            if(ch == 'Y')
                cntY++;
        }
        int n = customers.size();
        int penalty = INT_MAX, res = 0, cntN = 0;
        for(int i = 0; i < n; i++){
            if(cntY + cntN < penalty){
                res = i;
                penalty = cntY + cntN;
            }            
            if(customers[i] == 'Y')
                cntY--;
            else
                cntN++;
        }
        return cntN + cntY < penalty ? n : res;
    }
};