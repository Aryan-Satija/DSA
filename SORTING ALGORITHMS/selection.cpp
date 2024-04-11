#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&arr) {
    int n = arr.size();
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}