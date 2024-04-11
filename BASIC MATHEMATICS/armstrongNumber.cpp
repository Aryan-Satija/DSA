// CODING NINJAS -> ARMSTRONG NUMBERS
#include <bits/stdc++.h>
using namespace std;
int len(int n){
	int len = 0;
	while(n > 0){
		len++;
		n /= 10;
	}
	return len;
}
bool checkArmstrong(int n){

	int num = n, l = len(n);
	long long int sum = 0;
	while(num > 0){
		sum += pow(num%10, l);
		num /= 10;
	}
	return sum == n; 
}
