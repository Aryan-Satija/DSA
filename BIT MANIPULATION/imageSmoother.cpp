#include <bits/stdc++.h>
using namespace std;
// acc to the constraints, 0 <= grid[i][j] <= 255
// 255 = 2^8 - 1
// hence only 8 bits are required
// so we can store the value of each cell in the first 8 bits and then we can store the avg in the rest of the bits
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        int sum, cnt;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum = 0, cnt = 1;
                sum += (img[i][j]%256);
                if(i >= 1){
                    sum += (img[i-1][j]%256);
                    cnt++;
                    if(j >= 1) sum += (img[i-1][j-1]%256), cnt++;
                }
                if(j >= 1){
                    sum += (img[i][j-1]%256);
                    cnt++;
                    if(i + 1 < n) sum += (img[i+1][j-1]%256), cnt++;
                }
                if(i + 1 < n){
                    sum += (img[i+1][j]%256);
                    cnt++;
                    if(j + 1 < m) sum += (img[i+1][j+1]%256), cnt++;
                }
                if(j + 1 < m){
                    sum += (img[i][j+1]%256);
                    cnt++;
                    if(i >= 1) sum += (img[i-1][j+1]%256), cnt++;
                }
                img[i][j] = img[i][j] + ((sum/cnt)<<8);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                img[i][j] = (img[i][j]>>8);
        }
        return img;
    }
};