// LEETCODE -> Maximum Nesting Depth of the Parentheses
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, res = 0;
        for(auto ch : s)
        {
            if(ch == '(')
                res = max(res, ++depth);
            else if(ch == ')')
                --depth;
        }
        return res;
    }
};