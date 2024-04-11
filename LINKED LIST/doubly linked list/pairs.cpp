// CODING NINJAS -> Find pairs with given sum in doubly linked list
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
     int data;
     Node *prev;
     Node *next;
     Node() {
         this->data = 0;
         this->prev = NULL;
         this->next = NULL;
     }
     Node(int data) {
         this->data = data;
         this->prev = NULL;
         this->next = NULL;
     }
     Node (int data, Node *next, Node *prev) {
         this -> data = data;
         this -> prev = prev;
         this -> next = next;
     }
};
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> pairs;
    Node* temp = head;
    while(temp->next)
        temp = temp->next;
    Node* tail = temp;
    while(head != tail)
    {
        if(head->data + tail->data == k)
        {
            pairs.push_back({head->data, tail->data});
            head = head->next;
            if(head == tail) break;
            tail = tail->prev;   
        }
        else if(head->data + tail->data < k)
            head = head->next;
        else    
            tail = tail->prev;
    }
    return pairs;
}