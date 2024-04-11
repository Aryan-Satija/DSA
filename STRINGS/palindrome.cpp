// LEETCODE -> Valid Palindrome
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAlpha(char ch){
        if((ch >= 'A' and ch <= 'Z') or (ch >= 'a' and ch <= 'z') or (ch >= '0' and ch <= '9'))
            return true;
        return false;
    }
    bool isPalindrome(string s) {   
        int n = s.length();
        for(int i = 0; i < n; i++)
            s[i] = tolower(s[i]);

        int low = 0, high = n - 1;
        while(low < high){
            if(!isAlpha(s[low]))
                low++;
            else{
                if(!isAlpha(s[high]))
                    high--;
                else{
                    if(s[low] != s[high])
                        return false;
                    low++;
                    high--;
                }
            }
        }
        return true;
    }
};