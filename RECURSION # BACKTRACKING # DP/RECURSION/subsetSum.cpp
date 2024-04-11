// CODING NINJAS -> SUBSET SUM - I
#include <bits/stdc++.h>
using namespace std;
void f(int index, vector<int> &nums, vector<int> &res, int sum){
	if(index == nums.size()){
		res.push_back(sum);
		return;
	}
	// include
	f(index + 1, nums, res, sum + nums[index]) ;
	// exclude
	f(index + 1, nums, res, sum) ;
}
vector<int> subsetSum(vector<int> &nums){
	vector<int> res;
	f(0, nums, res, 0);
	sort(res.begin(), res.end());
	return res;	
}