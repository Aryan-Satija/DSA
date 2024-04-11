#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int, int> expand(int low, int high, string str){
        while(low >= 0 and high < str.size()){
            if(str[low] == str[high]) low--, high++;
            else break;
        }
        return {low+1, high-1};
    }
    string longestPalindrome(string s) {
        int low = 0, high = 0;
        for(int i = 1; i < s.size(); i++){
            auto p = expand(i, i, s);
            if(p.second - p.first > high - low)
                low = p.first, high = p.second;    
            if(s[i] == s[i-1]){
                auto p = expand(i-1, i, s);
                if(p.second - p.first > high - low)
                    low = p.first, high = p.second;   
            }
        }
        return s.substr(low, high - low + 1);
    }
};