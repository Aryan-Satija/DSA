// CODING NINJAS -> PAINTER'S PARTITION
#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &boards, int k, int time){
    int sum = 0;
    for(auto num : boards){
        if(sum + num <= time) sum += num;
        else{
            sum = num;
            k--;
        }
    }
    return k > 0;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = 0, high = 0;
    for (auto len : boards) {
        low = max(low, len);
        high += len;
    }
    while(low < high){
        int mid = (high+low)/2;
        if(isPossible(boards, k, mid))
            high = mid;
        else low = mid+1;
    }
    return low;
}