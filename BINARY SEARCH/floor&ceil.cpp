// CODING NINJAS -> Ceil The Floor
#include <bits/stdc++.h>
using namespace std;
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// finding floor
	int floor = -1, ceil = -1;
	int low = 0, high = (n-1);
	while(low <= high){
		int mid = (low+high)/2;
		if(a[mid] > x) high = mid-1;
		else{
			floor = a[mid];
			low = mid + 1;
		}
	}
	// finding ceil
	low = 0, high = (n-1);
	while(low <= high){
		int mid = (low+high)/2;
		if(a[mid] >= x){
			ceil = a[mid];
			high = mid-1;
		} 
		else low = mid + 1;
	}
	return {floor, ceil};
}