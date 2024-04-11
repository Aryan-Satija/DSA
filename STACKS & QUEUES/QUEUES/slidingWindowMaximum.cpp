#include <bits/stdc++.h>
using namespace std;
vector<int> approach1(vector<int> &nums, int n, int k){
        deque<int> dq;
        int maxi = INT_MIN;
        for(int i = 0; i < k; i++)
        {
            dq.push_back(nums[i]);
            maxi = max(maxi, nums[i]);
        }
        int start = 0, end = k - 1;
        vector<int> ans;
        while(end < (n - 1))
        {
            ans.push_back(maxi);
            if(dq.front() != maxi)
            {
                end++;        
                maxi = max(maxi, nums[end]);
                dq.push_back(nums[end]);
                dq.pop_front(); 
            }
            else
            {
                end++;
                dq.pop_front();
                dq.push_back(nums[end]);
                maxi = dq.front();
                for(auto num : dq)
                    maxi = max(maxi, num);
            }
        }
        ans.push_back(maxi);
        return ans;
}
vector<int> approach2(vector<int> &nums, int n, int k){
    deque<int> dq; // doubly linked list
    int s = 0, e = 0;
    vector<int> ans;
    while(e < n)
    {
        if((e - s) == k){
            ans.push_back(nums[dq.front()]);
            if(s == dq.front())
                dq.pop_front();
            s++;
        } else {
            while (!dq.empty() and nums[dq.back()] <= nums[e])
                dq.pop_back();
            dq.push_back(e);
            e++;
        }
    }
    if ((e - s) == k)
        ans.push_back(nums[dq.front()]);
    return ans;
}