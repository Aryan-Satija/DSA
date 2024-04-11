// LEETCODE ->  Isomorphic Strings
#include <bits/stdc++.h>
using namespace std;
bool isIsomorphic(string x, string y) {
    unordered_map<char, char> mp_x, mp_y;
    for(int i = 0; i < x.length(); i++){
        if(mp_x.find(x[i]) == mp_x.end()){
            if(mp_y.find(y[i]) == mp_y.end())
                mp_x[x[i]] = y[i], mp_y[y[i]] = x[i];
            else
                return false;
        }   
        else{
            if(mp_y.find(y[i]) == mp_y.end())
                return false;
            if(mp_x[x[i]] != y[i])
                return false;
        }
    }
    return true;
}