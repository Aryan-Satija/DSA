// CODING NINJAS -> Reverse A Doubly Linked List
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node* next;
    Node* prev;
    int data;
    Node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};
#include <bits/stdc++.h> 
Node* reverseDLL(Node* head)
{   
    Node* prev = NULL;    
    Node* curr = head;    
    Node* fwd = head->next;
    while(curr != NULL)
    {
        curr->next = prev;
        curr->prev = fwd;
        prev = curr;
        curr = fwd;
        if(fwd != NULL)
        {
            fwd = fwd->next;
        }
    }
    return prev;    
}


