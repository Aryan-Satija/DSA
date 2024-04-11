// iterative method
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseList(ListNode* head) {
    if(head == NULL or head->next == NULL)
        return head;
    ListNode *curr = head, *prev = NULL, *fwd = head->next;
    while(curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = fwd;
        if(fwd)
            fwd = fwd->next;
    }
    return prev;
}
