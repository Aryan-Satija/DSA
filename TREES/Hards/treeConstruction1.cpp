// LEETCODE -> Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* util(int low, int high, int &i, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &index)  
    {
        if(low > high) return NULL;
        int mid = index[preorder[i]];
        TreeNode* root = new TreeNode(preorder[i++]);
        if(high == low)
            return root;
        root->left = util(low, mid-1, i, preorder, inorder, index);
        root->right = util(mid+1, high, i, preorder, inorder, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> index;
        for(int i = 0; i < inorder.size(); i++) index[inorder[i]] = i;
        int in = 0;
        return util(0, preorder.size() - 1, in, preorder, inorder, index);    
    }
};