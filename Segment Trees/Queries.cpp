// LEETCODE ->  Range Sum Query - Mutable
#include <bits/stdc++.h>
using namespace std;
class NumArray {
    int n;
    vector<int> segment_tree;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        segment_tree.resize(4*n);
        buildtree(0, 0, n-1, nums);
    }
    void buildtree(int in, int low, int high, vector<int> &nums){
        if(low == high){
            segment_tree[in] = nums[low];
            return;
        }
        int mid = (low+high)/2;
        buildtree(2*in + 1, low, mid, nums);
        buildtree(2*in + 2, mid+1, high, nums);
        segment_tree[in] = segment_tree[2*in + 1] + segment_tree[2*in + 2];
    }
    void updateUtil(int in, int low, int high, int target_index, int val){
        if(target_index > high or target_index < low) return;
        if(low == high) {
            segment_tree[in] = val; 
            return;
        }
        int mid = (low+high)/2;
        updateUtil(2*in + 1, low, mid, target_index, val);
        updateUtil(2*in + 2, mid+1, high, target_index, val);
        segment_tree[in] = segment_tree[2*in + 1] + segment_tree[2*in + 2];
    }
    void update(int index, int val) {
        updateUtil(0, 0, n-1, index, val);
    }  
    int sumUtil(int in, int low, int high, int left, int right){
        if(high < left or low > right) return 0;
        if(low >= left and high <= right) return segment_tree[in];
        int mid = (low+high)/2;
        return sumUtil(2*in+1, low, mid, left, right) + sumUtil(2*in+2, mid+1, high, left, right);
    }
    int sumRange(int left, int right) {
        return sumUtil(0, 0, n-1, left, right);
    }
};