#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode {
   public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
vector<int> preOrder(TreeNode<int>* root){
    vector<int> preorder;
    stack<TreeNode<int>*> st;
    st.push(nullptr);
    while(root){
        if(root == st.top()){
            st.pop();
            if(root->right){
                root = root->right;
            }
            else root = st.top();
        }
        else{
            preorder.push_back(root->data);
            if(root->left){
                st.push(root);
                root = root->left;
            }
            else if(root->right){
                root = root->right;
            }
            else root = st.top();
        }
    }
    return preorder;
}