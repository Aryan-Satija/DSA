// CODING NINJAS -> Sorted Array
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
            int x = i;
            for(; x < n and a[x] == a[i]; x++);
            i = x;
        }
        else if(b[j] < a[i])
        {
            mergedArray.push_back(b[j]);
            int x = j;
            for(; x < m and b[x] == b[j]; x++);
            j = x;
        }
        else
        {
            mergedArray.push_back(a[i]);
            int x = i;
            for(; x < n and a[x] == a[i]; x++);
            i = x;

            int y = j;
            for(; y < m and b[y] == b[j]; y++);
            j = y;
        }
    }
    while(i < n)
    {
        mergedArray.push_back(a[i]);
        int x = i;
        for(; x < n and a[x] == a[i]; x++);
        i = x;
    }
    while(j < m)
    {
        mergedArray.push_back(b[j]);
        int y = j;
        for(; y < m and b[y] == b[j]; y++);
        j = y;
    }
    return mergedArray;
}