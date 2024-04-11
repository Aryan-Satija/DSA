// CODING NINJAS -> Insert at end of Doubly Linked List
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
Node * insertAtTail(Node *head, int k) {
    Node* node = new Node(k);
    if(head == NULL)
    {
       head = node;
       return head;
    }
    Node* temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = node;
    node->prev = temp;
    return head;
}