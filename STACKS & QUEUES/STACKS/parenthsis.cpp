// LEETCODE -> Valid Parentheses
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) 
{
    unordered_map<char, char> openingBracket;
    openingBracket[')'] = '(';
    openingBracket['}'] = '{';
    openingBracket[']'] = '[';
    stack<char> st;
    for(char bracket : s){
        if(bracket == '(' or bracket == '{' or bracket == '[')
            st.push(bracket);
        else{
            if(!st.empty() and openingBracket[bracket] == st.top())
                st.pop();
            else
                return false;
        }
    }
    return st.empty();
}