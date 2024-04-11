// LEETCODE -> CANDY
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n; // atleast 1 candy each
        int seq = 0, choco = 1, tower = -1;
        for(int i = 0; i < (n-1); i++)
        {
            if(ratings[i] > ratings[i + 1])
            {
                if(choco == 1)
                {
                    candies += (1 + seq);
                    seq++;
                    if((seq+1) == tower)
                    {
                        seq++;
                        candies++;
                        tower = -1;
                    }
                }
                else
                {
                    tower = choco;
                    seq = 0;
                }
                choco = 1;
            }
            else if(ratings[i] < ratings[i + 1])
            {
                candies += choco;
                choco++;
                seq = 0;
                tower = -1;
            }
            else{
                seq = 0;
                tower = -1;
                choco = 1;
            } 
        }
        return candies;
    }
};