// LEETCODE -> Sort List
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
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next)
            return head;
        // finding middle of the linkedlist.... 
        ListNode* hare = head, *turtle = head, *turtle_prev = NULL;
        while(hare and hare->next)
        {
            hare = hare->next->next;
            turtle_prev = turtle;
            turtle=turtle->next;
        }
        turtle_prev->next = NULL;
        ListNode* ll1= sortList(head);
        ListNode* ll2= sortList(turtle);
        
        // merging....
        if(!ll1)
            return ll2;
        if(!ll2)
            return ll1;

        ListNode *mergedhead = NULL, *mergedtail = NULL;
        if(ll1->val < ll2->val)
        {
            mergedhead = mergedtail = ll1; 
            ListNode* temp  = ll1->next;
            ll1->next = NULL;
            ll1 = temp;
        }
        else
        {
            mergedhead = mergedtail = ll2; 
            ListNode* temp  = ll2->next;
            ll2->next = NULL;
            ll2 = temp;
        }
        while(ll1 and ll2)
        {
            if(ll1->val < ll2->val)
            {
                mergedtail->next = ll1;
                mergedtail = ll1;
                ListNode* temp  = ll1->next;
                ll1->next = NULL;
                ll1 = temp;
            }
            else
            {
                mergedtail->next = ll2;
                mergedtail = ll2;
                ListNode* temp  = ll2->next;
                ll2->next = NULL;
                ll2 = temp;
            }
        }
        while(ll1)
        {
            mergedtail->next = ll1;
            mergedtail = ll1;
            ListNode* temp  = ll1->next;
            ll1->next = NULL;
            ll1 = temp;
        }
        while(ll2)
        {
            mergedtail->next = ll2;
            mergedtail = ll2;
            ListNode* temp  = ll2->next;
            ll2->next = NULL;
            ll2 = temp;
        }  
        return mergedhead;
    }
};