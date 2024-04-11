#include <bits/stdc++.h>
using namespace std;

int maxDigits(vector<int> arr, int n){
    int res = 0;
    for(auto num : arr){
        int dig = 0;
        while(num != 0){
            num /= 10;
            dig += 1;
        }
        res = max(res, dig);
    }
    return res;
}

void countSort(vector<int> &arr, int base){
    vector<int> count(10, 0);
    for(int i = 0; i < arr.size(); i++)
        count[(arr[i]/base)%10]++;

    for(int i = 1; i < 10; i++){
        count[i] = count[i] + count[i-1];
    }

    vector<int> output(arr.size());
    for(int i = arr.size() - 1; i >= 0; i--){
        output[count[(arr[i]/base)%10]-1] = arr[i];
        count[(arr[i]/base)%10]--;
    }

    for(int i = 0; i < arr.size(); i++){
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr, int n){
    int m = maxDigits(arr, n);

    int base = 1;
    for(int i = 1; i < m; i++){
        countSort(arr, base);
        base *= 10;
    }
}