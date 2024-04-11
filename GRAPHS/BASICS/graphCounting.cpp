//Code Studio -> Counting Graphs
#include <bits/stdc++.h>
using namespace std;
int countingGraphs(int N)
{
    int edges = (N*(N - 1))/2;
    return pow(2, edges);
}