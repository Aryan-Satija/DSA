// floyds cycle detection algorithm
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head) {
    ListNode* hare = head, *turtle = head;
    while(hare and hare->next)
    {
        hare = hare->next->next;
        turtle = turtle->next;
        if(hare == turtle)
            return true;
    }
    return false;
}