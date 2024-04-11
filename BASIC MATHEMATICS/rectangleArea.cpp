// LEETCODE -> RECTANGLE AREA
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // area-1
        int a1 = (ay2 - ay1)*(ax2 - ax1);

        // area-2
        int a2 = (by2 - by1)*(bx2 - bx1);
        
        if(by2 < ay1 or by1 > ay2 or bx1 > ax2 or ax1 > bx2)
            return a1 + a2;
        
        // common area
        int ca = (min(ay2, by2) - max(ay1, by1))*(min(ax2, bx2) - max(ax1, bx1));

        return (a1 + a2 - ca);
    }
};