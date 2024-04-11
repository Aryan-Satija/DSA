//LEETCODE -> Repeated String Match
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // rabin karp algorithm
    const int base = 31;
    const int mod = 1e9 + 7;
    bool rabin_karp(string a, string b){
        int n = b.size();

        // is "b" a substring of "a" ? 
        vector<int> multiplier(n, 1);
        for(int i = 1; i < n; i++) multiplier[i] = (multiplier[i-1]*1LL*base)%mod;

        // getting hashcode of b
        int b_code = 0, a_code = 0;
        for(int i = 0; i < n; i++){
            b_code = (b_code + ((b[i] - 'a' + 1)*1LL*multiplier[n-i-1])%mod)%mod;
            a_code = (a_code + ((a[i] - 'a' + 1)*1LL*multiplier[n-i-1])%mod)%mod;
        }
        int left = 0, right = n - 1;
        while(right < a.size()){
            if(a_code == b_code){
                // compare strings
                bool flag = true;
                for(int i = 0; i < b.size(); i++){
                    if(a[left+i] != b[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag) return true;
            }
            // perform rolling hash
            a_code = (a_code - ((a[left] - 'a' + 1)*1LL*multiplier[n-1])%mod + mod)%mod;
            left++, right++;
            if(right < a.size())
                a_code = ((a_code*1LL*base)%mod + (a[right] - 'a' + 1))%mod;
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        if(a == b) return 1;
        string source = "";
        int count = 0;
        while(source.size() < b.size()) source += a, count++;
        if(rabin_karp(source, b)) return count;
        if(rabin_karp(source + a, b)) return count + 1;
        return -1;
    }
};