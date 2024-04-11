// LEETCODE -> Merge Sorted Array
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = (m - 1), p2 = (n - 1);
    int fptr = (m + n -1);
    while(p1 >= 0 and p2 >= 0)
    {
        if(nums1[p1] < nums2[p2])
            nums1[fptr--] = nums2[p2--];
        else
            nums1[fptr--] = nums1[p1--];
    }
    while(p2 >= 0)
        nums1[fptr--] = nums2[p2--];
    while(p1 >= 0)
        nums1[fptr--] = nums1[p1--];
}