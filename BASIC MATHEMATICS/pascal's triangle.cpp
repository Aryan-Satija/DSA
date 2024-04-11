// LEETCODE ->  Pascal's Triangle
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int n) {
    if(n == 1)
        return {{1}};
    if(n == 2)
        return {{1}, {1,1}};
    vector<vector<int>> pascalTriangle;
    pascalTriangle.push_back({1});
    for(int i = 2; i <= n; i++)
    {
        vector<int> pascalRow(i);
        pascalRow[0] = pascalRow[i-1] = 1;
        for(int j = 1; j < (i - 1); j++)
            pascalRow[j] = (pascalTriangle[i-2][j-1] + pascalTriangle[i-2][j]);
        pascalTriangle.push_back(pascalRow);
    }
    return pascalTriangle;
}