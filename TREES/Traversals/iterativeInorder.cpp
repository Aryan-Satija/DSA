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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        st.push(nullptr);
        while(root){
            if(root == st.top()){
                st.pop();
                inorder.push_back(root->val);
                if(root->right) root = root->right;
                else root = st.top();
            }
            else{
                if(root->left){
                    st.push(root);
                    root = root->left;
                }
                else{
                    inorder.push_back(root->val);
                    if(root->right) root = root->right;
                    else root = st.top();
                }
            }
        }
        return inorder;
    }
};