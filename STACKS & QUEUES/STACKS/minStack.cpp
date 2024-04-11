// LEETCODE -> Min Stack
#include <bits/stdc++.h>
using namespace std;
class MinStack {
    stack<int> a;
    stack<int> b;
public:
    void push(int val) {
        a.push(val);
        if(b.empty())
            b.push(val);
        else
            b.push(min(b.top(), val)); 
    }
    void pop() {
        a.pop();
        b.pop();
    }
    int top() {
        return a.top();
    }
    
    int getMin() {
        return b.top();
    }
};
