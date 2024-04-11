// LEETCODE -> Range Frequency Queries
#include <bits/stdc++.h>
using namespace std;
class RangeFreqQuery {
    int n;
    vector<unordered_map<int, int>> segment_tree;
    void buildTree(int in, int low, int high, vector<int> &arr){
        if(low == high){
            segment_tree[in][arr[low]]++;
            return;
        }
        int mid = (low+high)>>1;
        buildTree(2*in+1, low, mid, arr);
        buildTree(2*in+2, mid+1, high, arr);
        for(auto itr : segment_tree[2*in+1]) segment_tree[in][itr.first] += itr.second; 
        for(auto itr : segment_tree[2*in+2]) segment_tree[in][itr.first] += itr.second; 
    }
public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        segment_tree.resize(4*n);
        buildTree(0, 0, n-1, arr);
    }
    int freq_util(int in, int low, int high, int left, int right, int value){
        if(low > right or high < left) return 0;
        if(low >= left and high <= right) return segment_tree[in][value];
        int mid = (low+high)>>1;
        return freq_util(2*in+1, low, mid, left, right, value) + freq_util(2*in+2, mid+1, high, left, right, value);

    }
    int query(int left, int right, int value) {
        return freq_util(0, 0, n-1, left, right, value);
    }
};
// WE COULD HAVE ALSO APPLIED BINARY SEARCH ON THE INDICES ....