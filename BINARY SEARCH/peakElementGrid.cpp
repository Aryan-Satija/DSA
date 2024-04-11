// LEETCODE -> PEAK ELEMENT - 2
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m-1;
        while(low <= high){
            int mid = (low + high)/2;
            int max_row = 0;
            for(int i = 0; i < n; i++){
                if(mat[i][mid] > mat[max_row][mid]) max_row = i;
            }
            if(mid + 1 < m && mat[max_row][mid+1] > mat[max_row][mid]) low = mid + 1;
            else if(mid - 1 >= 0 && mat[max_row][mid-1] > mat[max_row][mid]) high = mid - 1;
            else return {max_row, mid};
        }
        return {-1, -1}; // dummy return 
    }
};