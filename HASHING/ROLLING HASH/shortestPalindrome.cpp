// LEETCODE -> Shortest Palindrome
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestPalindrome(string s) {
        // step-1 : finding longest palindromic substring starting from 0th index
        // eg : let str = abab
        // step-2 : convert str to abab#baba
        // step-3 : find longest prefix suffix of the new string using knp algorithm
        int n = s.size();
        string str = s;
        str = str + '#';
        for(int i = n-1; i >= 0; i--) str += s[i];
        
        // knp algo to generate lps lookup table
        vector<int> lps(2*n + 1, 0);
        for(int i = 1; i < (2*n + 1); i++){
            int cnt = lps[i-1];
            while(cnt > 0 && str[cnt] != str[i]) cnt = lps[cnt-1];
            if(str[cnt] == str[i]) cnt++;
            lps[i] = cnt;
        }
        // so, length longest palindromic substring starting from 0th index will be :
        int len = lps[2*n];
        
        // response string based upon the calculations : 
        string res = "";
        for(int i = n-1; i >= len; i--) res += s[i];
        for(int i = 0; i < len; i++) res += s[i];
        for(int i = len; i < n; i++) res += s[i];
        
        return res;
    }
};