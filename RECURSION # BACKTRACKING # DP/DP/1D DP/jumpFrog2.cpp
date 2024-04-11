#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<long long> dp(n, 0);

    for(int i = 1; i < n; i++){
        long long res = 1e12;
        for(int j = 1; j <= k and i >= j; j++){
            res = min(res, dp[i - j] + abs(a[i] - a[i-j]));
        }
        dp[i] = res;
    }

    cout << dp[n-1] << endl;
}
