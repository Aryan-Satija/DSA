// LEETCODE -> Lemonade Change
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill5 = 0, bill10 = 0;
        for(auto bill : bills)
        {
            if(bill == 5) bill5++;
            else if(bill == 10)
            {
                if(bill5 == 0) return false;
                bill5--;
                bill10++;
            }
            else
            {
                if(bill5 > 0 and bill10 > 0) bill5--, bill10--;
                else if(bill5 >= 3) bill5 -= 3;
                else return false;
            }
        }
        return true;
    }
};