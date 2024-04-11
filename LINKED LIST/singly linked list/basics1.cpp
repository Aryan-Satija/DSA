// Coding Ninjas -> Introduction To Linked List
#include<bits/stdc++.h>
using namespace std;
class Node 
{
public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};
Node* constructLL(vector<int>& arr) {
    if(arr.size() == 0)
        return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for(int i = 1; i < arr.size(); i++)
    {
        Node* new_node = new Node(arr[i]);
        tail->next = new_node;
        tail = new_node;
    }
    return head;
}