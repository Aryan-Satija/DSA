// CODING NINJAS -> BIT MANIPULATION
#include <bits/stdc++.h>
using namespace std;
vector<int> bitManipulation(int num, int i){
    int ithBit = num & 1 << (i - 1) ? 1 : 0;
    int set = (num | 1 << (i - 1));
    int clear = ~(1 << (i - 1)) & num;
    return {ithBit, set, clear};
}