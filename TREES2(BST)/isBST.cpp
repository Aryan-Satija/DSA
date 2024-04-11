// CODING NINJAS -> Binary Search Trees
#include <bits/stdc++.h>
using namespace std;
bool isValidBST(vector<int> &order){
    int last = 0;
    for(auto num : order){
        if(last >= num)
            return false;
        last = num;
    }
    return true;
}
