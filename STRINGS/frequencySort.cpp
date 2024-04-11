// LEETCODE -> Sort Characters By Frequency
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b){
    return a.second > b.second;
}
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<char, int>> freq(62, {'\0', 0});
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            if(ch > 'Z')
                freq[ch - 'a' + 36] = {ch, freq[ch - 'a' + 36].second + 1};
            else if(ch > '9')
                freq[ch - 'A' + 10] = {ch, freq[ch - 'A' + 10].second + 1};
            else
                freq[ch - '0'] = {ch, freq[ch - '0'].second + 1};
        }
        sort(freq.begin(), freq.end(), cmp);
        string res = "";
        for(int i = 0; i < 62; i++){
            char ch = freq[i].first;
            for(int j = 0; j < freq[i].second; j++)
                res += ch;
        }
        return res;
    }
};