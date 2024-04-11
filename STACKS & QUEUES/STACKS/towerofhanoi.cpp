#include <bits/stdc++.h>
using namespace std;
void f(int n, int source, int auxiliary, int destination, vector<vector<int>> &steps)
{
    if(n == 1)
    {
        steps.push_back({source, destination});
        return;
    }
    f(n-1, source, destination, auxiliary, steps);
    steps.push_back({source, destination});
    f(n-1, auxiliary, source, destination, steps);
} 
vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> steps;
    f(n, 1, 2, 3, steps);
    return steps;
}