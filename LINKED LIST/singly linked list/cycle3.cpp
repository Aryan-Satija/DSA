// node at which cycle begSins?
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *detectCycle(ListNode *head) {
    ListNode *hare = head, *turtle = head;
    while(hare and hare->next)
    {
        hare = hare->next->next;
        turtle = turtle->next;
        if(turtle == hare)
            break;
    }
    if(hare == NULL or hare->next == NULL)
        return NULL;
    turtle = head;
    while(turtle != hare)
    {
        hare = hare->next;
        turtle = turtle->next;
    }
    return turtle;
}