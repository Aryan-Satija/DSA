// LEETCODE -> Longest Common Prefix
#include <bits/stdc++.h> 
using namespace std;
class TrieNode{
    public: 
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;
        TrieNode(char data)
        {
            this->data = data;
            childCount = 0;
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
            currNode->childCount++;
        }    
        f(word.substr(1), currNode->children[word[0] - 'a']);
    }
    void insert(string word)
    {
        f(word, root);
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie T;
        for(auto str : strs) T.insert(str);
        string lcp = "";
        TrieNode *root = T.root;
        int i = 0;
        while(!root->isTerminal)
        {
            if(root->childCount == 1)
            {
                char ch = strs[0][i];
                root = root->children[ch -'a'];
                lcp.push_back(ch);
                i++;
            }
            else return lcp;
        }
        return lcp;
    }
};