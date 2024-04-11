// inorder :lnr
// preorder :nlr
// postorder :lrn
// CODING NINJAS -> Tree Traversals
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};
void util(TreeNode *root, vector<vector<int>> &res){
    if(root == NULL)
        return;
    res[1].push_back(root->data);
    util(root->left, res);
    res[0].push_back(root->data);
    util(root->right, res);
    res[2].push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> res(3);
    util(root, res);
    return res;
}
// level order traversal : DIY