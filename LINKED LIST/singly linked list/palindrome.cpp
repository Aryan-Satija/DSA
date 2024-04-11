// LEETCODE -> Palindrome Linked List 
// expected tc: O(n)
// expected sc: O(1)
#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    ListNode* next;
    int val;
    ListNode(int data)
    {
        this->val = data;
        next = NULL;
    }
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        ListNode* curr = head, *prev = NULL, *fwd = head->next, *temp = head;
        while(temp != NULL and temp ->next != NULL)
        {
            temp = temp->next->next;
            curr->next = prev;
            prev = curr; curr = fwd; fwd = fwd->next;
        }
        ListNode* nxt = temp == NULL ? curr : fwd;
        while(prev != NULL)
        {
            if(prev->val != nxt->val)
                return false;
                prev = prev->next; nxt = nxt->next;
        }
        return true;
    }
};