// CODING NINJAS -> Delete all occurrences of a given key in a doubly linked list
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;

};
Node* deleteAllOccurrences(Node* head, int key) {
    Node *curr = head;
    while(curr){
        if(curr->data == key){
            if(curr->prev){
                curr->prev->next = curr->next;
                if(curr->next)
                    curr->next->prev = curr->prev;
            }
            else{
                head = head->next;
                if(head)
                    head->prev = NULL;
            }
            curr = curr->next; 
        }
        else curr = curr->next;
    }
    return head;
}
