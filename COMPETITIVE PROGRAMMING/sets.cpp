#include <bits/stdc++.h>
using namespace std;
int main(){
    // INSERTION TIME COMPLEXITY : O( LOG(SIZE()) )
    // DELETION TIME COMPLEXITY : O( LOG(SIZE()) )
    // SEARCHING TIME COMPLEXITY : O( LOG(SIZE()) )
    // IMPLEMENTED USING SBBST
    // SBBST : SELF BALANCING BINARY SEARCH TREE
    set<int> s1;
    s1.insert(2);
    s1.insert(5);
    s1.insert(1);
    s1.insert(4);
    s1.insert(4);
    // SORTED ORDER WITHOUT REPETITION
    for(auto it = s1.begin(); it != s1.end(); it++)
        cout << *it << " ";
    cout << endl;
    s1.erase(4);
    for(auto it = s1.begin(); it != s1.end(); it++)
        cout << *it << " ";

    
}