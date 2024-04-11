// LEETCODE -> Excel Sheet Column Title
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber > 0){
            char ch = 'A' + (columnNumber - 1)%26; 
            res = ch + res, columnNumber = (columnNumber - 1)/26; 
        }
        return res;
    }
};