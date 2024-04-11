#include <bits/stdc++.h>
using namespace std;
void swapNumber(int &a, int &b) {
	a += b; 
	b = a-b;
	a -= b;
}
void swapNumber2(int &a, int &b) {
	a ^= b; 
	b ^= a;
	a ^= b;
}