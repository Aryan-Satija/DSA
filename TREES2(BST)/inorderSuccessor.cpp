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
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    int ceil = -1, floor = -1;
    TreeNode * temp = root;
    while(temp){
        if(key > temp->data){
            floor = temp->data;
            temp = temp->right;
        }
        else temp = temp->left;
    }
    temp = root;
    while(temp){
        if(key < temp->data){
            ceil = temp->data;
            temp = temp->left;
        }
        else temp = temp->right;
    }
    return {floor, ceil};
}