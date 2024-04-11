// CODING NINJAS -> Flatten A Linked List
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* bottom;
    Node(int val){
        this->data = val;
        next = NULL;
        bottom = NULL;
    }
};
Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
        if (root == NULL || root->next == NULL) 
            return root; 
        root->next = flatten(root->next); 
        root = mergeTwoLists(root, root->next); 
        return root; 
}