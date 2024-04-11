// LEETCODE -> Remove Outermost Parentheses
#include <bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) {
    string res = "";
    int bFactor = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(bFactor != 0)
        {
            if(s[i] == '('){
                bFactor++;
                res += '(';
            }
            else
                res = --bFactor == 0 ? res : res + ')';
        }
        else
            bFactor++;
    }
    return res;
}