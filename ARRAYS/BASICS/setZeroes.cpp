#include <bits/stdc++.h>
using namespace std;
// TC : O(M*N)
// SC : O(M + N)
void setZeroes(vector<vector<int>>& matrix) {
    vector<bool> rows(matrix.size(), false);
    vector<bool> cols(matrix[0].size(), false);
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }
    for(int i = 0; i < rows.size(); i++)
    {
        if(rows[i])
        {
            for(int j = 0; j < matrix[i].size(); j++)
                matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < cols.size(); i++)
    {
        if(cols[i])
        {
            for(int j = 0; j < matrix.size(); j++)
                matrix[j][i] = 0;
        }
    }
}
void setZeroes2(vector<vector<int>>& matrix) {
    int r = matrix.size(), c = matrix[0].size();
    bool flag1 = false, flag2 = false;
    for(int i = 0; i < r; i++)
    {
        if(matrix[i][0] == 0)
        {
            flag1 = true;
            break;
        }
    }
    for(int i = 0; i < c; i++)
    {
        if(matrix[0][i] == 0)
        {
            flag2 = true;
            break;
        }
    }
    for(int i = 1; i < r; i++)
    {
        for(int j = 1; j < c; j++)
        {
            if(matrix[i][j] == 0)
                matrix[i][0] = 0, matrix[0][j] = 0;
        }
    }
    for(int i = 1; i < r; i++)
    {
        for(int j = 1; j < c; j++)
        {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if(flag1)
    {
        for(int i = 0; i < r; i++)
            matrix[i][0] = 0;
    }
    if(flag2)
    {
        for(int i = 0; i < c; i++)
            matrix[0][i] = 0;
    }
}