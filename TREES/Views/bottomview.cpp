// CODING NINJAS -> Bottom View Of Binary Tree
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
};
vector<int> bottomView(BinaryTreeNode<int> *root)
{
    vector<int> BottomView;
    if(root == NULL)
        return BottomView;
    unordered_map<int, int> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    int leftmost = 0, rightmost = 0;
    while(!q.empty())
    {
        BinaryTreeNode<int> *node = q.front().first;
        int horizontal_distance = q.front().second;
        q.pop();
        mp[horizontal_distance] = node->data;
        if(node->left)
            q.push({node->left, horizontal_distance - 1});
        if(node->right)
            q.push({node->right, horizontal_distance + 1});
            
        leftmost = min(leftmost, horizontal_distance);
        rightmost = max(rightmost, horizontal_distance);
    }
    for(int i = leftmost; i <= rightmost; i++)
        BottomView.push_back(mp[i]);
    return BottomView;
}