// CODECHEF -> MAXIMUM DELICIOUSNESS
#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, pos, total;
	    cin >> n >> total >> pos;
	    vector<int> vec(n + 1);
	    vec[0] = INT_MAX;
	    for(int i = 1; i <= n; i++)
            cin >> vec[i];
	    sort(vec.begin(), vec.end(), greater<int>());
	    
	    long long int res = 0;
	    for(int x = pos; x <= n; x += total)
	        res += vec[x];
	    cout << res << endl;
	}
	return 0;
}