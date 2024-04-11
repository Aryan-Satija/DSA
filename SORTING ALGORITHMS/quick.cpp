#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int start, int end)
{
	int pivot = arr[start];
	int cnt = 0;
	for(int i = start + 1; i <= end; i++)
	{
		if(arr[i] <= pivot)
			cnt++;
	}
	int pivotIndex = start + cnt;
	swap(arr[start], arr[pivotIndex]);
	int i = start, j = end;
	while(i < pivotIndex and j > pivotIndex)
	{
		while(arr[i] <=  arr[pivotIndex])
			i++;
		while(arr[j] >  arr[pivotIndex])
			j--;
		if(i < pivotIndex and j > pivotIndex)
			swap(arr[i++], arr[j--]);
	}
	return pivotIndex;
}
void quickSort(int input[], int start, int end) 
{
	if(start >= end)
		return;
	int p = partition(input, start, end);
	quickSort(input, start, p-1);
	quickSort(input, p+1, end);
}