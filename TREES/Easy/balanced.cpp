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
pair<int, bool> util(TreeNode* root){
    if(!root)
        return {0, true};
    auto p1 = util(root->left);
    if(!p1.second) return {-1, false};
    auto p2 = util(root->right);
    if(!p2.second) return {-1, false};
    if(abs(p1.first - p2.first) > 1)
        return {-1, false};
    return {(1 + p1.first + p2.first), true};
}
bool isBalancedBT(TreeNode* root) 
{
    return util(root).second;
}

