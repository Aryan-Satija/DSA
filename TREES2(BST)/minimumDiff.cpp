// LEETCODE -> Minimum Absolute Difference in BST
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}
#include <bits/stdc++.h>
using namespace std;
void util(TreeNode* root, int &last, int &res){
    if(root == nullptr)
        return;
    util(root->left, last, res);
    res = min(res, root->val - last);
    last = root->val;
    util(root->right, last, res);
}
int getMinimumDifference(TreeNode* root) {
    int res = 1e9, last = -1e9;
    util(root, last, res);
    return res;
}