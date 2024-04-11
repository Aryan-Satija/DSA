#include <bits/stdc++.h>
using namespace std;
class TreeNode{
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int countNode(TreeNode *root){
    if(root == NULL)
        return 0;
    return (1 + countNode(root->left) + countNode(root->right));
}