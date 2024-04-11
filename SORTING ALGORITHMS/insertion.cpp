#include <bits/stdc++.h>
using namespace std;
void insertionSort(int n, vector<int> &arr){
    for(int i = 1; i < n; i++)
    {
        int num = arr[i];
        int j = i - 1;
        for(; j >= 0 and arr[j] > num; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = num;
    }
}