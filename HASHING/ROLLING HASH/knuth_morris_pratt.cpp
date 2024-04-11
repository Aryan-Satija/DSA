// Find the Index of the First Occurrence in a String

// RABIN KARP SOLUTION
// ROLLING HASH
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int base = 31;
    int mod = 1e9 + 7;
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()) return -1;
        int n = needle.size();
        vector<int> multiplier(n, 1);
        for(int i = 1; i < n; i++) multiplier[i] = (multiplier[i-1]*1LL*base)%mod;

        int needle_code = 0, haystack_code = 0;
        for(int i = 0; i < n; i++){
            needle_code = (needle_code + ((needle[i] - 'a' + 1)*1LL*multiplier[n - 1 - i])%mod)%mod;
            haystack_code = (haystack_code + ((haystack[i] - 'a' + 1)*1LL*multiplier[n - 1 - i])%mod)%mod;
        }
        int low = 0, high = n-1; 
        while(high < haystack.size()){
            if(needle_code == haystack_code){
                bool flag = true;
                for(int i = 0; i < n; i++){
                    if(needle[i] != haystack[low + i]){
                        flag = false;
                        break;
                    }
                }   
                if(flag) return low;
            }
            haystack_code = (haystack_code - (multiplier[n-1]*1LL*(haystack[low] - 'a' + 1))%mod + mod)%mod;
            low++; high++;
            haystack_code = ((haystack_code*1LL*base)%mod + (haystack[high] - 'a' + 1)%mod)%mod;
        }
        return -1;
    }
};

// KNP ALGORITHM
class Solution {
public:
    int strStr(string haystack, string needle) {
        // CONSTRUCTING LONGEST PREFIX SUFFIX TABLE
        vector<int> lps(needle.size(), 0);
        for(int i = 1; i < needle.size(); i++){
            int j = lps[i-1];
            while(j > 0 && needle[j] != needle[i])
                j = lps[j-1];
            if(needle[j] == needle[i]) j++;
            lps[i] = j; 
        }

        int haystack_ptr = 0, needle_ptr = 0;
        while(haystack_ptr < haystack.size()){
            while(needle_ptr > 0 && haystack[haystack_ptr] != needle[needle_ptr]) needle_ptr = lps[needle_ptr - 1];
            if(haystack[haystack_ptr] == needle[needle_ptr]) needle_ptr++;
            haystack_ptr++;
            if(needle_ptr == needle.size()) return (haystack_ptr - needle.size());
        }

        return -1;
    }
};

// dry run to find the lps lookup table for:
// a) a b a a b a b
//    0 0 1 1 2 3 2

// b) a b a b a a c a b a b
//    0 0 1 2 1 1 0 1 2 3 4   