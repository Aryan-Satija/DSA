#include <bits/stdc++.h>
using namespace std;
// LINEAR SEARCH => O(m*n)
// STAIRCASE SEARCH => O(m + n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = 0, col = matrix[0].size()-1;
        while(row < matrix.size() and col >= 0){
            if(matrix[row][col] < target) row++;
            else if(matrix[row][col] > target) col--;
            else return true;
        }
        return false;
    }
};
// BINARY SEARCH => O(logm + logn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = (rows*cols - 1);
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(matrix[mid/cols][mid%cols] > target)
                high = (mid-1);
            else if(matrix[mid/cols][mid%cols] < target)
                low = (mid+1);
            else
                return true;
        }
        return false;
    }
};
