// LEETCODE -> Longest Univalue Path
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int len = 1;
    pair<int, int> util(TreeNode* root){
        if(root == nullptr)
            return {0, 0};
        auto l = util(root->left);
        auto r = util(root->right);
        if(root->val == l.first){
            if(root->val == r.first){
                len = max(len, 1 + l.second + r.second);
                return {root->val, 1 + max(l.second, r.second)};
            }
            len = max(len, 1 + l.second);
            return {root->val, 1 + l.second};
        }
        if(root->val == r.first){
            len = max(len, 1 + r.second);
            return {root->val, 1 + r.second};
        }
        return {root->val, 1};
    }
    int longestUnivaluePath(TreeNode* root) {
        util(root);
        return len-1;
    }
};