// LEETCODE -> FIBONACCI NUMBERS
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int fib(int n) {
        return n == 0 or n == 1 ? n : fib(n - 1) + fib(n - 2);
    }
};