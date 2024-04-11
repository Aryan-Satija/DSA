// LEETCODE -> All Nodes Distance K in Binary Tree
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
    void getParents(TreeNode* root, TreeNode* par, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root == NULL)
            return;
        parent[root] = par;
        getParents(root->left, root, parent);
        getParents(root->right, root, parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        getParents(root, NULL, parent);
        queue<TreeNode*> q;
        q.push(target);
        int distance = 0;
        unordered_map<TreeNode*, bool> isVis;
        while(distance < k and !q.empty()){
            int size = q.size();
            for(int i = 1; i <= size; i++){
                auto node = q.front(); q.pop();
                isVis[node] = true; 
                if(node->left and !isVis[node->left])
                    q.push(node->left);
                if(node->right and !isVis[node->right])
                    q.push(node->right);
                if(parent[node] and !isVis[parent[node]])
                    q.push(parent[node]);
            }
            distance++;
        } 
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};  