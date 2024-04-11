// CODING NINJAS -> Subarrays with XOR ‘K’
#include<bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector<int> a, int tar) {
    unordered_map<int, int> mp; mp[0] = 1;
    int prefiXor = 0, res = 0;
    for(int i = 0; i < a.size(); i++)
    {
        prefiXor ^= a[i];
        if(mp.find(prefiXor^tar) != mp.end())
            res += mp[prefiXor^tar];
        mp[prefiXor]++;
    }
    return res;
}
