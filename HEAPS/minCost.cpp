#include <bits/stdc++.h>
using namespace std;
int minCost(int arr[], int n)
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++)
		pq.push(arr[i]);
	int res = 0;
	while(pq.size() > 1){
		int min1 = pq.top(); pq.pop(); 
		int min2 = pq.top(); pq.pop();
		res += (min1+min2);
		pq.push(min1 + min2); 
	}
	return res;
}
