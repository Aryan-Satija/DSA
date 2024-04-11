#include <bits/stdc++.h>
using namespace std;
// Stack class.
class Stack {
    int size;
    int i;
    int *arr;
    
public:
    Stack(int capacity) {
        this->size = capacity;
        arr = new int[capacity];
        i = -1;     
    }

    void push(int num) 
    {
        if(i == size - 1)
            return;
        arr[++i] = num;
    }
    int pop() 
    {
        if(i == -1)
            return -1;
        int elem = arr[i];
        i--;
        return elem;
    }
    int top()
    {
        if(i == -1)
            return -1;
        return arr[i];   
    }
    int isEmpty() 
    {
        if(i == -1)
            return true;
        return false; 
    }
    int isFull() 
    {
        if(i == size - 1)
            return true;
        return false;   
    }
    
};