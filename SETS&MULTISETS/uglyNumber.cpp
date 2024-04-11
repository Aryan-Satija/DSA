// LEETCODE -> UGLY NUMBER 2

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int nthUglyNumber(int n) {
        set<int> st;
        st.insert(1);
        long long int cnt = 1, res = 1;
        while(cnt < n){
            cnt += 1;
            st.erase(res);
            if(5*res <= INT_MAX){
                st.insert(5*res);
                st.insert(3*res);
                st.insert(2*res);
            }
            else if(3*res <= INT_MAX){
                st.insert(3*res);
                st.insert(2*res);
            }
            else if(2*res <= INT_MAX)
                st.insert(2*res);
            res = *(st.begin());
        }
        return res;
    }
};


class Solution2 {
public:
    int nthUglyNumber(int n) {
        vector<int> arr;
        arr.push_back(1);
        int res = 1;
        int l1 = 2, l2 = 3, l3 = 5;
        int i1 = 1, i2 = 1, i3 = 1;
        for(int cnt = 1; cnt < n; cnt++){
            res = min({l1, l2, l3});
            arr.push_back(res);
            if(res == l1){
                l1 = arr[i1]*2;
                i1++;
            }
            if(res == l2){
                l2 = arr[i2]*3;
                i2++;
            }
            if(res == l3){
                l3 = arr[i3]*5;
                i3++;
            }
        }
        return res;
    }
};  