#include <bits/stdc++.h>
using namespace std;
int beautySum(string s) {
    int n = s.length();
    int beauty = 0;
    for(int i = 0; i < n; i++){
        vector<int> freq(26, 0);
        int maxf = INT_MIN;
        for(int j = i; j < n; j++){
            char ch = s[j];
            freq[ch-'a']++;
            maxf = max(maxf, freq[ch-'a']);
            int minf = INT_MAX;
            for(int i = 0; i < 26; i++)
                minf = freq[i] != 0 ? min(minf, freq[i]) : minf;
            beauty += (maxf - minf);
        }
    }
    return beauty;
}