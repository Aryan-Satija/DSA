// CODING NINJAS -> CEIL FROM BST
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
    ~BinaryTreeNode() {
        if (left) {
          delete left;
        }
        if (right) {
          delete right;
        }
    }
};
int findCeil(BinaryTreeNode<int> *root, int x){
    int ceil = -1;
    while(root != nullptr){
        if(root->data >= x){
            ceil = root->data;
            root = root->left;
        }   
        else  root = root->right;
        
    }
    return ceil;
}