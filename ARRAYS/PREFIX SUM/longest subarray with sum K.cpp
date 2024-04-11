// CODING NINJAS -> Longest Subarray With Zero Sum
#include<bits/stdc++.h>
using namespace std;
int getLongestZeroSumSubarrayLength(vector<int> &arr){
	unordered_map<int, int> mp; mp[0] = -1;
	int prefixSum = 0, res = 0;
	for(int i = 0; i < arr.size(); i++)
	{
		prefixSum += arr[i];
		if(mp.find(prefixSum) == mp.end())
			mp[prefixSum] = i;
		else{
			res = max(res, i - mp[prefixSum]);
		}
	}
	return res;

}