// LEETCODE -> Maximum XOR of Two Numbers in an Array
#include <bits/stdc++.h> 
using namespace std;
class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();   
    }

    void insert(int num) {
        TrieNode* currNode = root;
        for (int i = 31; i >= 0; i--) {
            int currBit = (num >> i) & 1;
            if (!currNode->children[currBit])
                currNode->children[currBit] = new TrieNode();
            currNode = currNode->children[currBit];
        }
    }

    int maxXor(int num) {
        int res = 0;
        TrieNode* currNode = root;
        for (int i = 31; i >= 0; i--) {
            int currBit = (num >> i) & 1;
            int oppositeBit = 1 - currBit;

            if (currNode->children[oppositeBit]) {
                res |= (1 << i); // Set the i-th bit in res
                currNode = currNode->children[oppositeBit];
            } else {
                currNode = currNode->children[currBit];
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie prefixTree;
        for (auto num : nums)
            prefixTree.insert(num);

        int res = 0;
        for (auto num : nums)
            res = max(res, prefixTree.maxXor(num));
        return res;
    }
};
