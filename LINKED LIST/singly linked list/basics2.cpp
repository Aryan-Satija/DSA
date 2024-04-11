// LEETCODE -> Delete Node in a Linked List
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node, *fwd = node->next;
        curr->val = fwd->val;
        curr->next = fwd->next;
        fwd->next = NULL;
    }
};