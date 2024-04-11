#include <bits/stdc++.h>
using namespace std;
int main()
{
    // AVG CASE TC for insertion: O(1)
    // AVG CASE TC for deletion: O(1)
    // AVG CASE TC for searching: O(1)
    // WORST CASE TC for insertion: O(N)
    // WORST CASE TC for deletion: O(N)
    // WORST CASE TC for searching: O(N)
    // IMPLEMENTED USING HASHING TABLE

    unordered_set<int> s1;
    s1.insert(2);
    s1.insert(5);
    s1.insert(4);
    s1.insert(1);
    s1.insert(4);

    // UNORDERED BUT UNIQUE 
    for(auto it = s1.begin(); it != s1.end(); it++)
        cout << *it << " ";
}