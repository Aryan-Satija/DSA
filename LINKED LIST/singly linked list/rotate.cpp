// LEETCODE -> Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        int cnt = 1;
        ListNode* tail = head;
        while(tail->next)
        {
            cnt++;
            tail = tail->next;
        } 
        k = k%cnt;
        tail->next = head;
        for(int i = 1; i <= (cnt - k); i++)
        {
            head = head->next;
            tail = tail->next;
        }
        tail->next = NULL;
        return head;
    }
};