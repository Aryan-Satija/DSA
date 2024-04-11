#include <bits/stdc++.h>
using namespace std;
class TrieNode {                      
public:
    TrieNode * children[26];
    bool isTerminal;
    TrieNode()
    {
        isTerminal=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};
bool isEmpty(TrieNode* root)
{
    for(int i=0;i<26;i++)
        if(root->children[i])
            return false;      
    return true;
}
TrieNode* deleteUtil(TrieNode* root, string word)
{
    if(root == NULL)
        return NULL;
    if(word.length() == 0)
    {
        if(root->isTerminal)
            root->isTerminal = false;
        if(isEmpty(root))
        {
            delete root;
            root = NULL;
        }
        
        return root;
    }
    int index = word[0] - 'a';
    root->children[index] = deleteUtil(root->children[index], word.substr(1));
    if(isEmpty(root) && root->isTerminal == false)
    {
        delete root;
        root = NULL;
    }
    return root;
}

TrieNode* deleteWord(string word, TrieNode* root)
{
    return deleteUtil(root, word);
}