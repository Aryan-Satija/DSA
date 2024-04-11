// LEETCODE -> Binary Tree Maximum Path Sum
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
    int util(TreeNode* root, int &res){
        if(root == NULL)
            return 0;
        int left = util(root->left, res);
        int right = util(root->right, res);
        res = max({res, root->val, root->val + left, root->val + right, root->val + left + right});
        return max({root->val, root->val+left, root->val+right});
    }
    int maxPathSum(TreeNode* root) {
        int res = -1e9;
        util(root, res);
        return res;
    }
};

// minor optimisation:-
class Solution2 {
public:
    int util2(TreeNode* root, int &res){
        if(root == NULL)
            return 0;
        int left = util2(root->left, res);
        int right = util2(root->right, res);
        int temp = max({root->val, root->val+left, root->val+right});
        res = max({res, temp, root->val + left + right});
        return temp;
    }
    int maxPathSum2(TreeNode* root) {
        int res = -1e9;
        util2(root, res);
        return res;
    }
};