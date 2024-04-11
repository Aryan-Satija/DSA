// CODING NINJAS -> MORE SUBSEQUENCES
#include <bits/stdc++.h>
using namespace std;
int unique(int n,string a){
    vector<int> dp(n+1,-1);
    dp[0]=1;
    vector<int> occ(256,-1);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1]*2;

        if(occ[a[i-1]]!=-1){
            dp[i]-=dp[occ[a[i-1]]];
        }
        occ[a[i-1]]=i-1;
    }
    return dp[n];
}

string moreSubsequence(int n, int m, string a, string b)
{
    int countA=unique(n,a);
    int countB=unique(m,b);
    if(countA>=countB) return a;
    return b;
}