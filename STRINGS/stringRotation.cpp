// LEETCODE -> Rotate String
#include <bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal) {
    if(s.length() != goal.length())  return false;
    int n = s.length();
    for(int i = 1; i <= n; i++){
        char ch = s[n-1];
        s.pop_back();
        s = ch + s;
        if(s == goal)   
            return true;
    }
    return false;
}