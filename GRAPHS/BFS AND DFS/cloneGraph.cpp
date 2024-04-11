// LEETCODE -> CLONE GRAPH
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    unordered_map<Node*, Node*> clone;
    vector<bool> isVis;
    Node* cloneUtil(Node* node){
        if(isVis[node->val]) return clone[node];
        isVis[node->val] = true;
        Node* clone_node = new Node(node->val);
        clone[node] = clone_node;
        for(auto nbr : node->neighbors){
            Node* clone_nbr = cloneUtil(nbr);
            clone_node->neighbors.push_back(clone_nbr);
        }
        return clone_node;
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        isVis.resize(101, false);
        return cloneUtil(node);
    }
};