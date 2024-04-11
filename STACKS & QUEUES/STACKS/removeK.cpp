#include <bits/stdc++.h>
using namespace std;
string removeKDigits(string num, int k) 
{
    stack<char> st;
    for(auto dig : num)
    {
        while(!st.empty() and st.top() > dig and k > 0)
        {
            st.pop();
            k--;
        }
        if(!st.empty() or dig != '0')
            st.push(dig);
    }
    while(!st.empty() and k > 0)
    {
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    string ans = "";
    while(!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    return ans;
}