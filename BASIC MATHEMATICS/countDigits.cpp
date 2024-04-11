// CODING NINJAS -> COUNT DIGITS
#include <bits/stdc++.h>
using namespace std;
int countDigits(int n){
	int res = 0, num = n;
	while(num > 0){
		int dig = num%10;
		if(dig != 0 and n%dig == 0)
			res++;
		num /= 10;
	}
	return res;
}