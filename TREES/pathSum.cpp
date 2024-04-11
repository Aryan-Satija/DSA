// LEETCODE -> Path Sum
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return false;
        if(root->right == nullptr and root->left == nullptr)
            return root->val == targetSum;
        return hasPathSum(root->left, targetSum - root->val) or hasPathSum(root->right, targetSum - root->val);
    }
};