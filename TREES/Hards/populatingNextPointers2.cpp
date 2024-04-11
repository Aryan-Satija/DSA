// LEETCODE -> Populating Next Right Pointers in Each Node II
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        Node* itr = root->next;

        while(itr){
            if(itr->left) {
                itr = itr->left;
                break;
            }
            else if(itr->right){
                itr = itr->right;
                break;
            } 
            itr = itr->next;
        }

        if(root->left && root->right){
            root->left->next = root->right;
            root->right->next = itr;
        }
        else if(root->left) root->left->next = itr;
        else if(root->right) root->right->next = itr;
        connect(root->right);
        connect(root->left);
        return root;
    }
};