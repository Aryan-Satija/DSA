// LEETCODE -> longest common prefix
// APPROACH-1
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
    TrieNode *root;
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
    bool h(string prefix, TrieNode* currNode) {
        if(prefix == "")
            return true;
        if(currNode->children[prefix[0] - 'a']) 
            return h(prefix.substr(1), currNode->children[prefix[0] - 'a']);
        return false;  
    }
    bool startsWith(string prefix)
    {
        return h(prefix, root);
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie T;
        for(auto str : strs)
            T.insert(str);
        string lcp = "";
        TrieNode *root = T.root;
        while(!root->isTerminal)
        {
            int cnt = 0; char ch;
            for(int i = 0; i < 26; i++)
            {
                if(root->children[i])
                {
                    ch = 'a' + i;
                    cnt++;
                }
            }
            if(cnt == 1)
            {
                root = root->children[ch -'a'];
                lcp.push_back(ch);
            }
            else return lcp;

        }
        return lcp;
    }
};
// -------------------------------------------------------------------
// APPROACH-2
// #include <bits/stdc++.h> 
// using namespace std;
// class TrieNode{
//     public: 
//         char data;
//         TrieNode* children[26];
//         int childCount;
//         bool isTerminal;
//         TrieNode(char data)
//         {
//             this->data = data;
//             childCount = 0;
//             for(int i = 0; i < 26; i++) children[i] = NULL;
//             isTerminal = false;
//         }
// };
// class Trie {
// public:
//     TrieNode* root;
//     Trie() {
//         root = new TrieNode('*');   
//     }
//     void f(string word, TrieNode* currNode) {
//         if(word == "")
//         {
//             currNode->isTerminal = true;
//             return;
//         }
//         if(currNode->children[word[0] - 'a'] == NULL)
//         {
//             TrieNode* newNode = new TrieNode(word[0]);
//             currNode->children[word[0] - 'a'] = newNode;
//             currNode->childCount++;
//         }    
//         f(word.substr(1), currNode->children[word[0] - 'a']);
//     }
//     void insert(string word)
//     {
//         f(word, root);
//     }
// };
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         Trie T;
//         for(auto str : strs) T.insert(str);
//         string lcp = "";
//         TrieNode *root = T.root;
//         int i = 0;
//         while(!root->isTerminal)
//         {
//             if(root->childCount == 1)
//             {
//                 char ch = strs[0][i];
//                 root = root->children[ch -'a'];
//                 lcp.push_back(ch);
//                 i++;
//             }
//             else return lcp;
//         }
//         return lcp;
//     }
// };