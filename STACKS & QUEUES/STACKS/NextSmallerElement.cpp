#include <bits/stdc++.h> 
using namespace std;
vector<int> immediateSmaller(vector<int>& a)
{
	stack<int> st;
	int n = a.size();
	vector<int> NSE(n);
	for(int i = (n -1); i >= 0; i--)
	{
		while(!st.empty() and st.top() >= a[i])
			st.pop();
		NSE[i] = st.empty() ? -1 : st.top();
		st.push(a[i]);
	}
	return NSE;
}
