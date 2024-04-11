// hare-turtle algorithm
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* middleNode(ListNode* head) {
    ListNode* hare = head, *turtle = head;
    while(hare != NULL and hare->next != NULL)
    {
        hare = (hare->next)->next;
        turtle = turtle->next;
    }
    return turtle;
}
