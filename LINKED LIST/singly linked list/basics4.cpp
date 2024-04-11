// CODING NINJAS -> Count nodes of linked list 
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

int length(Node *head)
{
    int cnt = 0;
	while(head)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}