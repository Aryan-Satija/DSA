// CODING NINJAS -> Top View Of Binary Tree
#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
};
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> res;
    if(root == NULL) return res;
    unordered_map<int, int> util_map;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    int low = 0, high = 0;
    while(!q.empty()){
        TreeNode<int> *node = q.front().first;
        int displacement = q.front().second;
        q.pop();
        if(util_map.find(displacement) == util_map.end())
            util_map[displacement] = node->data;
        if(node->left)
            q.push({node->left, displacement - 1});
        if(node->right)
            q.push({node->right, displacement + 1});
        low = min(low, displacement);
        high = max(high, displacement);
    }
    for(int i = low; i <= high; i++)
        res.push_back(util_map[i]);
}