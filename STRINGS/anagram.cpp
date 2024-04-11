// LEETCODE -> Valid Anagram
#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string x, string y) {
    if(x.length() != y.length()) return false;
    vector<int> freq_x(26, 0), freq_y(26, 0);
    for(int i = 0; i < x.length(); i++)
        freq_x[x[i]-'a']++, freq_y[y[i]-'a']++;
    for(int i = 0; i < 26; i++){
        if(freq_x[i] != freq_y[i]) return false;
    }
    return true;
}