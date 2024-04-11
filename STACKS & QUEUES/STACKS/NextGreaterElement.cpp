// LEETCODE -> NEXT GREATER ELEMENT-1
// TC : O(2*n) // since in the first worst case, every element can be visited twice.(when the array is sorted in the increasing order)
// SC : O(1)
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int, int> NGE;
    for(int i = (nums2.size() - 1); i >= 0; i--)
    {
        while(!st.empty() and st.top() < nums2[i])
            st.pop();
        NGE[nums2[i]] = st.empty() ? -1 : st.top();
        st.push(nums2[i]);
    }
    vector<int> ans;
    for(auto num : nums1)
        ans.push_back(NGE[num]);
    return ans;
}