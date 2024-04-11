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
    int util(TreeNode* root, int &diameter){
        if(!root)
            return 0;
        int l = util(root->left, diameter);
        int r = util(root->right, diameter);
        diameter = max(l+r, diameter);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        util(root, diameter);
        return diameter;
    }
};