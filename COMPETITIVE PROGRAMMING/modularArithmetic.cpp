// quotient - remainder algorithm
// dividend = ((divisor * quotient) + remainder)


// simple deduction
// a % b = remainder when b divides a
// a = b*(quotient) + (a % b)
// a % b = (a - (b * [ a / b ]))
// where [.] is the gif function 


// modular addition
// (a + b) % m = ((a % m) + (b % m)) % m 


// modular multiplication
// (a * b) % m = ((a % m) * (b % m)) % m 

// modular division not follows 
// (a / b)%m != ((a%m) / (b%m))%m

// LEETCODE -> Smallest Integer Divisible by K
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2 == 0 || k%5 == 0)
            return -1;
        int rem = 1, dig = 1;
        for(int i = 1; i <= k; i++){
            if(rem%k == 0)
                return dig;
            rem = rem*10 + 1;
            rem = rem%k;
            dig++;
        }
        return -1;
    }
};
