// MORRIS TRAVERSAL (INORDER)
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
        vector<int> res;
        TreeNode* itr = root;
        while(itr){
            if(itr->left == nullptr){
                res.push_back(itr->val);
                itr = itr->right;
            }
            else{
                TreeNode* prev = itr->left;
                while(prev->right && prev->right != itr) prev = prev->right;
                if(prev->right == nullptr){
                    prev->right = itr;
                    itr = itr->left;
                }
                else{
                    prev->right = nullptr;
                    res.push_back(itr->val);
                    itr = itr->right;
                }
            }
        }
        return res;
    }
};