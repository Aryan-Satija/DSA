// LEETCODE -> reorganise string
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<char, int> a, pair<char, int> b){
    return a.second > b.second;
}
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<pair<char, int>> freq(26);
        for(int i = 0; i < 26; i++)
            freq[i] = {'a' + i, 0};
        for(auto ch : s)
            freq[ch-'a'].second++;
        sort(freq.begin(), freq.end(), cmp);
        if( freq[0].second > (n + 1)/2 )
            return "";
        
        string res(n, ' ');
        int j = 0;
        for(int i = 0; i < 26 and freq[i].second != 0; i++){
            for(int k = 1; k <= freq[i].second; k++){
                res[j] = freq[i].first;
                j += 2;
                if(j >= n)
                    j = 1;
            }
        }
        return res;
    }
};