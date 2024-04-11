// CODING NINJAS -> Two Numbers With Odd Occurrences
#include <bits/stdc++.h>
using namespace std;
vector<int> twoOddNum(vector<int> arr){
    int Xor = 0;
    for(auto num : arr)
        Xor = Xor^num;
    int setBitPos;
    for(int i = 0; i < 32; i++){
        if(Xor & (1 << i)){
            setBitPos = i;
            break;
        }
    }
    int a = 0, b = 0;
    for(auto num : arr)
        a = (num & (1 << setBitPos)) ? a^num : a; 
    b = Xor ^ a;
    vector<int> result;
    if(a > b)
        result.push_back(a), result.push_back(b);
    else    
        result.push_back(b), result.push_back(a);
    return result;
}
