// CODING NINJAS -> LOWER BOUND
#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> arr, int n, int x) {
	if(x > arr[n-1]) return n;
	int low = 0, high = n-1;
	while(low < high){
		int mid = (low + high)/2;
		if(arr[mid] < x) low = mid + 1;
		else high = mid; 
	}
	return low; // or high
}
