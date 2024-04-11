#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<int> mergeSort(int low, int high, vector<int> &a){
    if(low == high) return a;
    int mid = (low + high)/2;
    vector<int> arr1 = mergeSort(low, mid, a);
    vector<int> arr2 = mergeSort(mid+1, high, a);
    // arr1 -> low ---- mid
    // arr2 -> mid + 1 ---- high
    int ptr1 = low, ptr2 = mid+1;
    while(ptr1 <= mid && ptr2 <= high){
        if(arr1[ptr1] <= arr2[ptr2])
            a[low++] = arr1[ptr1++];
        else {
            a[low++] = arr2[ptr2++];
            cnt += (mid - ptr1 + 1);
        }
    }
    while (ptr1 <= mid)
        a[low++] = arr1[ptr1++];
    while (ptr2 <= high)
        a[low++] = arr2[ptr2++];
    return a;
}
int numberOfInversions(vector<int>&a, int n) {
    mergeSort(0, n-1, a);
    return cnt;
}