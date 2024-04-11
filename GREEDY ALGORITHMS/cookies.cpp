// LEETCODE -> Assign Cookies
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // approach-1
    int approach1(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end(), greater<int>());
        int cnt = 0;
        int childIndex = 0;
        for(auto size : s)
        {
            while(childIndex < g.size() and g[childIndex] > size)
                childIndex++;
            if(childIndex == g.size())
                break;
            else
            {
                childIndex++;
                cnt++;
            }
        }
        return cnt;
    }

    // approach-2
    int approach2(vector<int>& g, vector<int>& s) {
        // Sort the children's greed factors and the cookies' sizes in non-increasing order
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        
        int contentChildren = 0;
        int i = 0; // Index for the children's greed factors
        int j = 0; // Index for the cookies' sizes
        
        // Use a max heap to store the available cookie sizes
        priority_queue<int> pq;
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                contentChildren++; // Assign the cookie to the child
                i++; // Move on to the next child
                j++; // Move on to the next cookie
            } else {
                pq.push(s[j]); // Add the cookie to the heap
                j++; // Move on to the next cookie
            }
        }
        // Use the remaining cookies in the heap to satisfy the remaining children
        while (i < g.size() && !pq.empty()) {
            if (pq.top() >= g[i]) {
                contentChildren++; // Assign the cookie to the child
                i++; // Move on to the next child
                pq.pop(); // Remove the cookie from the heap
            } else {
                break; // The remaining cookies in the heap are too small to satisfy the remaining children
            }
        }
        return contentChildren;
    }
};