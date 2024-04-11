#include <bits/stdc++.h>
using namespace std;
int main(){
    int n = 4;
    vector<vector<int>> mat1(n, vector<int>(n));
    vector<vector<int>> mat2(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> mat1[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> mat2[i][j];
    }

    vector<vector<int>> c(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += (mat1[i][k]*mat2[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << c[i][j] << " ";
        cout << endl;
    }
}