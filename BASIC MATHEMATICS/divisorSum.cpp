// CODING NINJAS -> DIVISOR SUM
#include <bits/stdc++.h>
using namespace std;
// naive approach : O(n*√n) : DIY...

// optimised : O(n)
int sumOfAllDivisors(int n){
	int sum = 0;
	for(int i = 1; i <= n; i++)
		sum += (i * (n/i));
	return sum;
}
// further optimised : O(√n) 
int sumOfAllDivisors(int n){
	int sum = 0;
	for(int i = 1; i <= sqrt(n); i++){
		sum += (i * (n/i));
		if(i != (n/i)){
			int l = n/(i+1), h = n/i;
			sum += (i*( (h*(h+1))/2 - (l*(l+1))/2 ));
		}
	}
	return sum;
}