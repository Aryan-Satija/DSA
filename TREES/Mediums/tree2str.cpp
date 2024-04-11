// LEETCODE -> Construct String from Binary Tree
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
    string tree2str(TreeNode* root) {
        if(root == nullptr)
            return "";
        string str = "";
        int num = abs(root->val);
        while(num) {
            char dig = (num%10 + '0');
            str = dig + str;
            num = num/10;
        }
        str = root->val > 0 ? str : (root->val == 0 ? "0" : '-' + str);
        if(root->right)
            str = str + '(' + tree2str(root->left) +')' + '(' + tree2str(root->right) +')';
        else if(root->left)
            str = str + '(' + tree2str(root->left) +')';
        return str;
    }
};