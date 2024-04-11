#include <bits/stdc++.h>
using namespace std;
// using maps
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
bool hasCycle(ListNode *head) {
    unordered_map<ListNode *, bool> isVisited;
    ListNode *iterator = head;
    while(iterator)
    {
        if(isVisited[iterator])
            return true;
        isVisited[iterator] = true;
        iterator = iterator->next;
    }
    return false;
}
