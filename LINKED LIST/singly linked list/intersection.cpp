// LEETCODE -> Intersection of Two Linked Lists

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* itr = headA;
        while(itr->next)
            itr = itr->next;
        ListNode* tail = itr;
        tail->next = headB;
        ListNode* ans = detectCycle(headA);
        tail->next = NULL;
        return ans;
    }
};