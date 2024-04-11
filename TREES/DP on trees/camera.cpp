// LEETCODE -> Binary Tree Cameras 
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
    int cnt = 0;
    void traverse(TreeNode* node){
        if(node == nullptr) return;
        node->val = cnt++;
        traverse(node->left);
        traverse(node->right);
    }
    int f(TreeNode* node, bool parent_camera, bool choice, vector<vector<vector<int>>> &dp){
        if(!node)
            return choice ? 0 : 1e9; 
        if(dp[node->val][parent_camera][choice] != -1) return dp[node->val][parent_camera][choice];
        if(!choice)
            return dp[node->val][parent_camera][choice] = 1 + f(node->left, 1, 1, dp) + f(node->right, 1, 1, dp);
        if(parent_camera)
            return dp[node->val][parent_camera][choice] = min(1 + f(node->left, 1, 1, dp) + f(node->right, 1, 1, dp), f(node->left, 0, 1, dp) + f(node->right, 0, 1, dp));
        return dp[node->val][parent_camera][choice] = min({1 + f(node->left, 1, 1, dp) + f(node->right, 1, 1, dp), 
                        f(node->left, 0, 0, dp) + f(node->right, 0, 1, dp),
                        f(node->left, 0, 1, dp) + f(node->right, 0, 0, dp)});
    }
    int minCameraCover(TreeNode* root) {
        traverse(root);
        vector<vector<vector<int>>> dp(cnt, vector<vector<int>>(2, vector<int>(2, -1)));
        return f(root, 0, 1, dp);
    }
};