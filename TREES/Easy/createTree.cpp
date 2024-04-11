// CODING NINJAS -> Create Binary Tree
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left, *right;
    Node(){
        this->data = 0;
        left = NULL;
    }
    Node(int data){
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
Node* createTree(vector<int>&arr){
    Node* head = new Node(arr[0]);
    queue<Node*> q;
    q.push(head);
    for(int i = 1; i < arr.size(); i++){
        Node *front = q.front();
        q.pop();
        Node* l = new Node(arr[i++]);
        front->left = l;
        q.push(l);
        if(i < arr.size()){
            Node* r = new Node(arr[i]);
            front->right = r;
            q.push(r);
        }
    }
    return head;
}