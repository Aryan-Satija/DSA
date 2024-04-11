// CODING NINJAS -> Introduction To Doubly Linked List
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
Node* constructDLL(vector<int>& arr) {
    if(arr.size() == 0)
        return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for(int i = 1; i < arr.size(); i++)
    {
        Node* new_node = new Node(arr[i]);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    return head;
}