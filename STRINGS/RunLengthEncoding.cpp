// LEETCODE => String Compression
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = '\0';
        int len = 0, j = 0, n = chars.size();
        for(int i = 0; i < n; i++){
            if(chars[i] != prev){
                if(len > 1){
                    for(auto ch : to_string(len))
                        chars[j++] = ch;
                }
                chars[j++] = chars[i];
                prev = chars[i];
                len = 1;
            }
            else
                len++;
            prev = chars[i];
        }
        
        if(len > 1){
            for(auto ch : to_string(len))
                chars[j++] = ch;
        }

        return j;
    }
};