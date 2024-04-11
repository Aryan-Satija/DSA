// LEETCODE -> Palindrome Partitioning
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void f(int index, int n, vector<string> &partition, vector<vector<string>> &partitions, vector<vector<string>> &palindromes)  
    {
        if(index == n){
            partitions.push_back(partition);
            return;
        }
        for(auto palindrome : palindromes[index]){
            partition.push_back(palindrome);
            f(index + palindrome.size(), n, partition, partitions, palindromes);
            partition.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindromes;
        for(int i = 0; i < s.size(); i++){
            string str = "";
            vector<string> palindrome;
            for(int j = i; j < s.size(); j++){
                str += s[j];
                // checking if palindrome 
                int start = i, end = j;
                bool flag = true;
                while(start < end){
                    if(s[start++] != s[end--]){
                        flag = false;
                        break;
                    }
                }
                if(flag) 
                    palindrome.push_back(str);
            }
            palindromes.push_back(palindrome);
        }
        vector<vector<string>> partitions;
        vector<string> partition;
        f(0, s.size(), partition, partitions, palindromes);
        return partitions;
    }
};