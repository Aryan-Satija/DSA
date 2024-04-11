#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr, int l, int mid, int r)
{
    vector<int> temp;
    int low = l, high = mid+1;
    while(low <= mid and high <= r)
    {
        if(arr[low] <= arr[high])
        {
            temp.push_back(arr[low]);
            low++;
        }
        else
        {
            temp.push_back(arr[high]);
            high++;
        }
    }
    while(low <= mid)
    {
        temp.push_back(arr[low]);
        low++;
    }
    while(high <= r)
    {
        temp.push_back(arr[high]);
        high++;
    }
    for(int i = l; i <= r; i++)
        arr[i] = temp[i - l];
}
void mergeSort(vector<int>& arr, int l, int r) {
    if(l == r)
        return;
    int mid = (l+r)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}