#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class BSTIterator {
public:
    TreeNode* root;
    TreeNode* low;
    bool flag;
    BSTIterator(TreeNode* root) {
        this->root = root;
        low = root;
        while(low->left) low = low->left;
        flag = true; 
    }
    int next() {
        int res = low->val;
        // getting inorder successor of res or finding the ceil value of res;
        TreeNode* ceil = nullptr;
        low = root;
        while(low){
            if(res < low->val){
                ceil = low;
                low = low->left;
            }
            else
                low = low->right;
        }
        if(ceil == nullptr)
            flag = false;
        low = ceil;
        return res;   
    }
    bool hasNext() {
        return flag;
    }
};
// hence now do inorder successor and inorder predecessor
