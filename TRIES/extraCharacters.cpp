// LEETCODE -> EXTRA CHARACTERS IN A STRING
#include <bits/stdc++.h> 
using namespace std;
class TrieNode{
    public: 
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char data)
        {
            this->data = data;
            for(int i = 0; i < 26; i++) children[i] = NULL;
            isTerminal = false;
        }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('*');   
    }
    void f(string word, TrieNode* currNode) {
        if(word == "")
        {
            currNode->isTerminal = true;
            return;
        }
        if(currNode->children[word[0] - 'a'] == NULL)
        {
            TrieNode* newNode = new TrieNode(word[0]);
            currNode->children[word[0] - 'a'] = newNode;
        }    
        f(word.substr(1), currNode->children[word[0] - 'a']);
    }
    void insert(string word)
    {
        f(word, root);
    }
    bool g(string word, TrieNode* currNode) {
        if(word == "")
            return currNode->isTerminal;
        if(currNode->children[word[0] - 'a']) 
            return g(word.substr(1), currNode->children[word[0] - 'a']);
        return false;  
    }
    bool search(string word)
    {
        return g(word, root);
    }
};
class Solution {
public:
    int f(int index, string &s, Trie &pt, vector<int> &dp){
        if(index == s.size())
            return 0;
        if(dp[index] != -1)
            return dp[index];
        string str = "";
        int res = 1 + f(index + 1, s, pt, dp);
        for(int i = index; i < s.size(); i++){
            str += s[i];
            if(pt.search(str))
                res = min(res, f(i + 1, s, pt, dp) );
        }
        return dp[index] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        Trie prefixTree;
        for(auto word : dictionary)
            prefixTree.insert(word);
        vector<int> dp(s.size(), -1);
        return f(0, s, prefixTree, dp); 
    }
};