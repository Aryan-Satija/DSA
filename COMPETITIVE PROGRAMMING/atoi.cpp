// a.to.i => ascii to integer
#include <bits/stdc++.h>
using namespace std;
int main(){
    int i = atoi("120");
    cout << i+5 << endl;
    int j = atoi("         120");
    cout << j+5 << endl;
    int k = atoi("125.5");
    cout << k << endl;
    int l = atoi("125.999");
    cout << l << endl;
    int s = atoi("5+120");
    cout << s << endl;
}