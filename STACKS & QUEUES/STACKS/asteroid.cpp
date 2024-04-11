// LEETCODE -> Asteroid Collision
#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for(auto meteor : asteroids)
    {
        if(meteor >= 0)
            st.push(meteor);
        else
        {
            while(!st.empty() and st.top() >= 0 and st.top() < abs(meteor))
                st.pop();
            if(st.empty() or st.top() < 0)
                st.push(meteor);
            else if(st.top() == abs(meteor))
                st.pop();
        }
    }
    int n = st.size();
    vector<int> finalState(n);
    for(int i = (n - 1); i >= 0; i--)
    {
        finalState[i] = st.top();
        st.pop();
    }
    return finalState;
}