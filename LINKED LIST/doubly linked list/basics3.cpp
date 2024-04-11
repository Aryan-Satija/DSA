// CODING NINJAS -> Delete Last Node of a Doubly Linked List
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
Node* deleteLastNode(Node *head) {
    if(head == NULL or head->next == NULL)
        return NULL;
    Node* temp = head;
    while(temp->next->next != NULL)
        temp = temp->next;
    temp->next = NULL;
    return head;
}
