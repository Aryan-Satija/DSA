// LEETCODE -> Spiral Matrix
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& input) 
    {
        vector<int> output;
        int n = input.size(), m = input[0].size();
        int row_start = 0, row_end = (n - 1), col_start = 0, col_end = (m - 1);

        while(row_start <= row_end && col_start <= col_end)
        {
            for(int i = col_start; i <= col_end; i++)
                output.push_back(input[row_start][i]);
            row_start++;
            for(int i = row_start; i <= row_end; i++)
                output.push_back(input[i][col_end]);
            col_end--;
            
            if(row_start > row_end || col_start > col_end)
                break;
            
            for(int i = col_end; i >= col_start; i--)
                output.push_back(input[row_end][i]);
            row_end--;
            for(int i = row_end; i >= row_start; i--)
                output.push_back(input[i][col_start]);
            col_start++;
        }

        return output;
    }
};