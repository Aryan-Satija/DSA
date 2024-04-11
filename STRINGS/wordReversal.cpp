// LEETCODE -> Reverse Words in a String
#include <bits/stdc++.h>
using namespace std;
string trim(string s)
{
    int st = 0;
    while(st < s.size() and s[st] == ' ')
        st++;
    int end = (s.size() - 1);
    while(end >= 0 and s[end] == ' ')
        end--;
    return st > end ? "" : s.substr(st, end - st + 1);
}
string reverseWords(string s) {
    s = trim(s);
    int i = 0;
    string res = "";
    while(i < s.size())
    {
        string word = "";
        while(i < s.size() and s[i] != ' ')
            word += s[i++];
        res = (res == "") ? word : word + ' ' + res ;
        while(i < s.size() and s[i] == ' ')
            i++;
    }
    return res;
}