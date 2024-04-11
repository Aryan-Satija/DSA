// LEETCODE -> Maximum Length of Pair Chain
#include <bits/stdc++.h>
using namespace std;
bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),cmp);
        int end = -1e9, cnt = 0, n = pairs.size();
        for(int i = 0; i < n; i++){
            if(pairs[i][0] > end){
                cnt++;
                end = pairs[i][1];
            }    
        }
        return cnt;
    }
};