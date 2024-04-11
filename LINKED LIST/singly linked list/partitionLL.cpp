// LEETCODE -> Partition List
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* partition(ListNode* head, int x) {
    if(head == NULL or head->next == NULL) return head;
    ListNode *h1 = NULL, *t1 = NULL, *h2 = NULL, *t2 = NULL;
    ListNode *itr = head;
    while(itr){
        if(itr->val < x){
            if(t1 == NULL)
                h1 = t1 = itr;
            else{
                t1->next = itr;
                t1 = itr;
            }
        }
        else{
            if(t2 == NULL)
                h2 = t2 = itr;
            else{
                t2->next = itr;
                t2 = itr;
            }
        }
        itr = itr->next;
    }
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    t1->next = h2;
    t2->next = NULL;
    return h1;
}
// optimised
ListNode* partition2(ListNode* head, int x) {
    if(head == NULL or head->next == NULL) return head;
    ListNode *h1 = new ListNode(-1), *t1 = h1, *h2 = new ListNode(-1), *t2 = h2;
    ListNode *itr = head;
    while(itr){
        if(itr->val < x){
            t1->next = itr;
            t1 = itr;
        }
        else{
            t2->next = itr;
            t2 = itr;
        }
        itr = itr->next;
    }
    if(h2 == NULL) return h1;
    t1->next = h2->next;
    t2->next = NULL;
    return h1->next;
}