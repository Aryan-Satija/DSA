// LEETCODE -> LONGEST HAPPY PREFIX
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPrefix(string s) {
        // KNP ALGORITHM
        int n = s.size();
        vector<int> lps(n, 0);
        for(int i = 1; i < n; i++){
            int j = lps[i-1];
            while(j > 0 && s[j] != s[i]) j = lps[j-1];
            if(s[j] == s[i]) j++;
            lps[i] = j;
        }   
        int len = lps[n-1];
        string res = "";
        for(int i = 0; i < len; i++) res += s[i];
        return res;
    }
};