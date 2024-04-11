// LEETCODE -> Valid Parenthesis String
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // approach1
    bool approach1(string s) {
        int open = 0, close = 0, star = 0;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            char ch = s[i];
            if(ch == '(') open++;
            else if(ch == ')') close++;
            else star++;

            //check
            if(open + star < close) return false;
        }

        open = 0, close = 0, star = 0;
        for(int i = (n - 1); i >= 0; i--)
        {
            char ch = s[i];
            if(ch == '(') open++;
            else if(ch == ')') close++;
            else star++;

            //check
            if(close + star < open) return false;
        }
        return true;
    }
    
    // approach2
    bool approach2(string s) {
        int cmin = 0, cmax = 0;
        for (char c : s) {
            if (c == '(')
                cmax++, cmin++;
            if (c == ')')
                cmax--, cmin = max(cmin - 1, 0);
            if (c == '*')
                cmax++, cmin = max(cmin - 1, 0);
            if (cmax < 0) return false;
        }
        return cmin == 0;
    }
};