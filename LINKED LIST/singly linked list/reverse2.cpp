// recursive method
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* rev(ListNode* prev, ListNode* curr, ListNode* fwd)
{
    if(curr == NULL) return prev;
    curr->next = prev;
    return fwd ? rev(curr, fwd, fwd->next) : rev(curr, fwd, NULL);
}
ListNode* reverseList(ListNode* head) {
    if(head == NULL or head->next == NULL)
        return head;
    return rev(NULL ,head, head->next);
}  