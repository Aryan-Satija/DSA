// LEETCODE -> Repeated DNA Sequences
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n < 10) return {};
        vector<string> res;
        long long hash=0;
        int input[n];
        unordered_map<long long,int> map;
        if(n<10) return res;
        for(int i=0; i<n; i++){
            if(s[i]=='A') input[i]=1;
            else if(s[i]=='C') input[i]=2;
            else if(s[i]=='G') input[i]=3;
            else input[i]=4;
        }
        for(int i=0;i<10;i++){
            hash = (hash*4) + input[i];
        }
        map[hash]++;
        for(int i=1;i<n-9;i++){
            hash = hash*4 - input[i-1]*pow(4,10) + input[i+9];
            map[hash]++;
            if(map[hash]==2) res.push_back(s.substr(i,10));
        }
        return res;
      }
};