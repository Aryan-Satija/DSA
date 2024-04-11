// CODING NINJAS ->  Minimize Max Distance to Gas Station
#include <bits/stdc++.h>
using namespace std;
double minimiseMaxDistance(vector<int> &arr, int k){
	double low = 0, high = 0;
	double mid = 0;
	for(int i = 1; i < arr.size(); i++)
		high = max(high, (double)(arr[i] - arr[i-1]));
	double res = high;
	while(low + 1e-6 < high){
		mid = (low + high)/2.0;
		int stations = 0;
		for(int i = 1; i < arr.size(); i++){
			int stationsbw = (arr[i] - arr[i-1])/mid;
			stations = (arr[i] - arr[i-1]) == mid*stations ? stations + stationsbw - 1 : stations + stationsbw;
		}
		if(stations <= k){
			res = mid;
			high = mid;
		}
		else
			low = mid;
	}
	return res;
}
