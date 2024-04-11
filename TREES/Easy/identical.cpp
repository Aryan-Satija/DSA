// LEETCODE -> CHECK IF TWO TREES ARE IDENTICAL OR NOT?
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr and q == nullptr)
            return true;
        if(p == nullptr or q == nullptr)
            return false;
        return ((p->val == q->val) and isSameTree(p->left, q->left) and isSameTree(p->right, q->right));
    }
};