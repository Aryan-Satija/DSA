// LEETCODE -> NEXT GREATER ELEMENT-2
#include <bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)
        return {-1};
    stack<int> st;
    for(int i = (n - 2); i >= 0; i--)
    {
        if(nums[i] > nums[n-1])
            st.push(nums[i]);
    }
    vector<int> ans(n);
    for(int i = (n - 1); i >= 0; i--)
    {
        while(!st.empty() and st.top() <= nums[i])
            st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }
    return ans;
}