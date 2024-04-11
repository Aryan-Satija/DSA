// LEETCODE -> Minimum Operations to Make a Special Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int index, string &num){
        if(index < 0)
            return 0;
        if(num[index] == '0'){
            int cnt = 0;
            for(int i = (index-1); i>= 0; i--){
                if(num[i] == '0' || num[i] == '5')
                    break;
                cnt++;
            }
            return min(cnt, 1 + f(index-1, num));
        }
        else if(num[index] == '5'){
            int cnt = 0;
            bool flg = false;
            for(int i = (index-1); i>= 0; i--){
                if(num[i] == '2' || num[i] == '7'){
                    flg = true;   
                    break;
                }
                cnt++;
            }
            if(flg)
                return min(cnt, 1 + f(index-1, num));
        }
        return 1 + f(index - 1, num);
    }
    int minimumOperations(string num) {
        return f(num.size()-1, num);
    }
};