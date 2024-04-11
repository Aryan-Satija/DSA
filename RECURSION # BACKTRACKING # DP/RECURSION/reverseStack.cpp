// CODING NINJAS -> Reverse Stack Using Recursion
#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &stack, int num)
{
    if(stack.empty())
    {
        stack.push(num);
        return;
    }
    int top = stack.top();
    stack.pop();
    insertAtBottom(stack, num);
    stack.push(top);
}
void reverseStack(stack<int> &stack) 
{
    if(stack.empty())
    {
        return;
    }
    int top = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, top);
}