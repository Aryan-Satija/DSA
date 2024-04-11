// CODING NINJAS -> Find length of Loop
#include <bits/stdc++.h>
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
int lengthOfLoop(Node *head) {
    Node* hare = head, *turtle = head;
    do
    { 
        hare = hare->next->next;
        turtle = turtle->next;
    }while(hare != turtle);
    turtle = head;
    while(turtle != hare)
    {
        turtle = turtle->next;
        hare = hare->next;
    }
    int cnt = 0;
    do
    {
        hare = hare->next;
        cnt++;
    }while(hare != turtle);
    return cnt;
}
