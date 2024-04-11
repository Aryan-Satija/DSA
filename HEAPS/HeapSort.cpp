#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int> &arr, int index, int n)
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < n and arr[left] > arr[largest])
        largest = left;
    if(right < n and arr[right] > arr[largest])
        largest = right;
    if(largest != index)
    {
        swap(arr[index], arr[largest]);
        heapify(arr, largest, n);
    }
}
vector<int> heapSort(vector<int>& arr, int n) 
{
    for(int i = ((n/2) - 1); i >= 0; i--) heapify(arr, i, n);   
    
    for(int i = (n-1); i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        n--;
        heapify(arr, 0, n);
    }
    return arr;
}