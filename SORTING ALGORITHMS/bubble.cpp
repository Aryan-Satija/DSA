#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n) 
{
    for(int j = (n - 1); j >= 0; j--)
    {
        for(int i = 1; i <= j; i++)
        {
            if(arr[i] < arr[i - 1])
                swap(arr[i], arr[i-1]);
        }
    }
}