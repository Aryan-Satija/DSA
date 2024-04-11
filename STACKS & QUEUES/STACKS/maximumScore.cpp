// LEETCODE -> Maximum Score of a Good Subarray
#include <bits/stdc++.h>
using namespace std;
// approach 1
typedef pair<int, int> P;
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        stack<P> pse;
        vector<int> prev(n, -1);
        for(int i = 0; i < n; i++){
            while(!pse.empty() and pse.top().first >= nums[i]) pse.pop();
            if(!pse.empty()) prev[i] = pse.top().second;
            pse.push({nums[i], i});
        }
        stack<P> nse;
        vector<int> next(n, n);
        for(int i = n-1; i >= 0; i--){
            while(!nse.empty() and nse.top().first >= nums[i]) nse.pop();
            if(!nse.empty()) next[i] = nse.top().second;
            nse.push({nums[i], i});
        }
        long long int res = 0;
        for(int i = 0; i < n; i++){
            int left = prev[i] + 1, right = next[i] - 1;
            if(left <= k and right >= k and (right - left + 1)*nums[i] > res)
                res = (right - left + 1)*nums[i];
        }
        return res;
    }
};

// approach 2
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int minN = nums[k];
        int low = k, high = k, res = minN;
        while(low > 0 or high < nums.size()-1){
            if(low == 0)
                minN = min(minN, nums[++high]); 
            else if(high == nums.size()-1)
                minN = min(minN, nums[--low]);
            else{
                if(nums[low-1] > nums[high+1]) minN = min(minN, nums[--low]);
                else minN = min(minN, nums[++high]);
            } 
            res = max(res, minN*(high - low + 1));
        }
        return res;

    }
};