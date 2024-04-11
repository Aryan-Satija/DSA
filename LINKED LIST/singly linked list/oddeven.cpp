// leetcode ->  Odd Even Linked List
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* oddEvenList(ListNode* head) {
    if(!head or !head->next or !head->next->next)
        return head;
    ListNode* tail = head;
    int len = 1;
    while(tail->next) 
    {
        len++;
        tail = tail->next;
    } 
    ListNode* curr = head, *prev = NULL;
    for(int i = 1; i <= len; i++)
    {
        if(i%2 == 0)
        {
            prev->next = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = prev->next; 
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}