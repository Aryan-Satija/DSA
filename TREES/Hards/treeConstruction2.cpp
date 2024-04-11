// leetcode -> Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* util(int low, int high, int &in, vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &index){
        if(high < low)
            return NULL;
        int mid = index[postorder[in]];
        TreeNode* root = new TreeNode(postorder[in--]);
        if(high == low)
            return root;
        root->right = util(mid + 1, high, in, inorder, postorder, index);
        root->left = util(low, mid - 1, in, inorder, postorder, index);
        return root;    
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> index;
        for(int i = 0; i < inorder.size(); i++) index[inorder[i]] = i;
        int in = inorder.size()-1;
        return util(0, inorder.size()-1, in, inorder, postorder, index); 
    }
};