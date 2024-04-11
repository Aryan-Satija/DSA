// CODING NINJAS -> Find The Single Element
#include <bits/stdc++.h>
using namespace std;
#include<vector>
int getSingleElement(vector<int> &arr){
	int n = arr.size();
	int low = 0, high = (n-1);
	while(low <= high)
	{
		int mid = (low + high)/2;
		if(mid == 0 or mid == (n-1))   return arr[mid];
		if(arr[mid] == arr[mid + 1])
		{
			if(mid%2 == 0)
				low = (mid + 1);
			else 
				high = (mid - 1);
		}
		else if(arr[mid] == arr[mid - 1])
		{
			if(mid%2 == 0)
				high = (mid - 1);
			else 
				low = (mid + 1);
		}
		else
			return arr[mid];
	}
}