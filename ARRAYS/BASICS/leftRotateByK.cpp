// LEETCODE -> Rotate array
#include <bits/stdc++.h> 
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // FAST INPUT/ OUTPUT
       
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int k;
    cin >> k;
    
    k %= n;
    
    vector<int> temp(arr.begin(), arr.end());
    
    for(int i = 0; i < n; i++)
        arr[(i - k + n)%n] = temp[i];
    
    for(auto num : arr)
        cout << num << " ";
    
    return 0;
}