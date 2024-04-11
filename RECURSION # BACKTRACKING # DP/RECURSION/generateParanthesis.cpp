// LEETCODE -> GENERTAE PARENTHESIS
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(vector<string> &res, string str, int depth, int n){
        if(depth < 0 or depth > (2*n - str.length()))  
            return;
        if(str.length() == 2*n){
            res.push_back(str);
            return;
        }

        f(res, str + '(', depth + 1, n);
        f(res, str + ')', depth - 1, n);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string brackets = "";
        f(res, brackets, 0, n);
        return res;
    }
};