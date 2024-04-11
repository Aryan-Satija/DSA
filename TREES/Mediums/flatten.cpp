// LEETCODE -> Flatten Binary Tree to Linked List
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
    pair<TreeNode*, TreeNode*> util(TreeNode* root){
        if(!root) return {nullptr, nullptr};
        auto l = util(root->left);
        auto r = util(root->right);
        if(l.first == nullptr){
            if(r.first == nullptr) return {root, root};
            root->right = r.first; 
        }
        else{
            root->left = nullptr;
            root->right = l.first;
            if(r.first == nullptr) return {root, l.second};
            l.second->right = r.first;
        }
        return {root, r.second};
    }
    void flatten(TreeNode* root) {
        util(root);
    }
};