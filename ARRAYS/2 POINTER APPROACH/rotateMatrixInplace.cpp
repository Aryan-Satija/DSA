// LEETCODE -> ROTATE IMAGE

#include <bits/stdc++.h>
using namespace std;
// APPROACH-1
void rotate1(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int left = 0, right = (n - 1), up = 0, down = (n - 1);
    while(left < right)
    {   
        for(int var = 0; var < (right - left); var++)
        {
            int tlX = (left + var), tlY = up;
            int trX = right, trY = (up + var);
            int brX = (right-var), brY = down;
            int blX = left, blY = (down-var);
            int tl = matrix[tlY][tlX];
            int tr = matrix[trY][trX];
            int bl = matrix[blY][blX];
            int br = matrix[brY][brX];
            matrix[tlY][tlX] = bl;
            matrix[trY][trX] = tl;
            matrix[brY][brX] = tr;
            matrix[blY][blX] = br;
        }
        left++; right--; up++; down--;
    }
}
// APPROACH-2 (TRANSPOSE + REVERSING EVERY ROW)
void rotate2(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++)
    {
    	for(int j = (i + 1); j < n; j++)
    		swap(matrix[i][j], matrix[j][i]);
    }
    for(int i = 0; i < n; i++)
    	reverse(matrix[i].begin(), matrix[i].end());
}