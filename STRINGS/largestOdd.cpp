// LEETCODE -> Largest Odd Number in String
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int i = (num.size() - 1);
        for(; i >= 0 and !((num[i] - '0')&1); i--);
        return i == -1 ? "" : num.substr(0, i + 1);
    }
};