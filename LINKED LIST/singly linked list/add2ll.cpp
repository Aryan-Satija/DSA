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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL, * tail = NULL;
        int carryin = 0;
        while(l1 != NULL and l2 != NULL)
        {
            ListNode* temp = new ListNode((l1->val + l2->val + carryin)%10);
            if(head == NULL)
                head = tail = temp;
            else
            {
                tail -> next = temp; 
                tail = temp;
            }
            carryin = (l1->val + l2->val + carryin)/10;
            l1 = l1->next; l2 = l2->next;
        }
        while(l1 != NULL)
        {           
            ListNode* temp = new ListNode((l1->val + carryin)%10);
            tail -> next = temp; 
            tail = temp;        
            carryin = (l1->val + carryin)/10;
            l1 = l1->next;
        }
        while(l2 != NULL)
        {           
            ListNode* temp = new ListNode((l2->val + carryin)%10);
            tail -> next = temp; 
            tail = temp;        
            carryin = (l2->val + carryin)/10;
            l2 = l2->next;
        }
        if(carryin == 1)
        {
            ListNode* temp = new ListNode(1);
            tail -> next = temp; 
            tail = temp;   
        }

        return head;
    }
};