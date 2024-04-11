#include <bits/stdc++.h>
using namespace std;

string huffman_encoding(string s){
  
   // abaabcd
    map<char, int> f;
    for(auto ch : s)
        f[ch]++;
    

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    
    for(auto itr : f){
      pq.push({itr.second, string(1, itr.first)});
    }
    
    map<char, string> hash;
    
    while(pq.size() > 1){
        auto left = pq.top();
        pq.pop();
        auto right = pq.top();
        pq.pop();
        for(auto ch : left.second)
            hash[ch] = "0" + hash[ch];
        for(auto ch : right.second)
            hash[ch] = "1" + hash[ch];    
        pq.push({left.first + right.first, left.second + right.second});
    }


    for(auto itr : hash){
        cout << itr.first << " " << itr.second << endl; 
    } 
}

int main(){
  huffman_encoding("abaabcd");
}
