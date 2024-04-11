// LEETCODE -> ZIGZAG TRAVERSAL
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        bool left2right = true;
        int level_length = 1;
        vector<int> level;
        while(!q.empty()){
            level_length = q.size();
            level.resize(level_length);
            for(int i = 0; i < level_length; i++){
                level[i] = (q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            if(!left2right){
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
            left2right = !left2right;
        }
        return res;
    }
};