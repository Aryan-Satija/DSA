// CODING NINJAS -> L to R XOR
#include <bits/stdc++.h>
using namespace std;
int findXOR(int L, int R){
    long long int res = 0;
    for(long long int i = 1; i < 32; i++){
        long long int bitR = ((R + 1)/(1 << i))*(1 << (i - 1)) + max(0,(((R + 1)%(1 << i)) - (1 << (i - 1))));
        long long int bitL = ((L + 1)/(1 << i))*(1 << (i - 1)) + max(0,(((L + 1)%(1 << i)) - (1 << (i - 1))));
        long long int bitTotal = (L&(1<<(i-1))) ? (bitR - bitL + 1) : (bitR - bitL);
        if(bitTotal & 1)
            res = res + (1 << (i - 1));
    } 
    return res;
}
/* the simple logic explanation
      L,R

range[3,5]       

(1^2^3^4^5)^(1^2)  = (3^4^5)

xor(1to R)^xor(1 to L-1)



xor till 1= 1       1

xor till 2=3        n+1

xor till 3 = 0       0

xor till 4 = 4       n

xor till 5= 1

xor till 6=7

xor till 7 = 0

xor till 8 = 8

*/



int Xorupto(int num)
{
    if(num%4==0)return num;
    else if(num%4==1)return 1;
    else if(num%4==2)return num+1;
    else return 0;
}
int findXOR2(int L, int R){
   return Xorupto(R)^Xorupto(L-1);
}