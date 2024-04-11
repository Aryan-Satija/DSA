// LEETCODE -> Construct Binary Search Tree from Preorder Traversal
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
    TreeNode* buildBST(int &i, int low, int high, vector<int> &inorder, vector<int> &preorder, unordered_map<int, int> &index){
        if(i >= inorder.size() || low > high) return nullptr;
        TreeNode* newNode = new TreeNode(preorder[i++]);
        newNode->left = buildBST(i, low, index[newNode->val] - 1, inorder, preorder, index);
        newNode->right = buildBST(i, index[newNode->val] + 1, high, inorder, preorder, index);
        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map<int, int> index;
        for(int i = 0; i < inorder.size(); i++)
            index[inorder[i]] = i;
        int i = 0;
        return buildBST(i, 0, inorder.size() - 1, inorder, preorder, index);
    }   
};