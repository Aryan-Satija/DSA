// CODING NINJAS -> SORTED ARRAY
#include <bits/stdc++.h>
using namespace std;
vector<int> sortedArray(vector<int> a, vector<int> b) 
{
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    vector<int> mergedArray;
    while(i < n and j < m)
    {
        if(a[i] < b[j])
        {
            mergedArray.push_back(a[i]);
            i++;
        }
        else
        {
            mergedArray.push_back(b[j]);
            j++;
        }
    }
    while(i < n)
    {
        mergedArray.push_back(a[i]);
        i++;
    }
    while(j < m)
    {
        mergedArray.push_back(b[j]);
        j++;
    }
    return mergedArray;
}