// LEETCODE ->  Copy List with Random Pointer
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
		int data;
		Node *next;
 		Node *random;
		Node() : data(0), next(nullptr), random(nullptr){};
		Node(int x) : data(x), next(nullptr), random(nullptr) {}
		Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
};
Node *cloneLL(Node *head){
    // inserting nodes in b/w the given linked list
    Node* itr = head;
    while(itr)
    {
        Node* temp = itr->next;
        itr->next = new Node(itr->data);
        itr->next->next = temp;
        itr = temp;
    }
    // cloning random pointers
    itr = head;
    while(itr)
    {
        itr->next->random = itr->random ? itr->random->next : NULL;
        itr = itr->next->next;
    }
    // segregating the nodes again
    Node* originaltail = head, *clonehead = head->next, *clonetail = head->next;
    int turn = 0;
    while(originaltail and clonetail)
    {
        if(turn%2 == 0)
        {
            originaltail->next = clonetail->next;
            originaltail = clonetail->next;
        }
        else
        {
            clonetail->next = originaltail->next;
            clonetail = originaltail->next;
        }
        turn += 1;
    }
    return clonehead;
}