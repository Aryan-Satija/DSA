#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
    int key;
    node* next;
    node(int key) {
        this->key = key;
        next = NULL;
    }
};

class sll {
    node* head;
    node* tail;

public:
    sll() {
        head = NULL;
        tail = NULL;
    }

    void append(int key) {
        node* newnode = new node(key);
        if (head) {
            tail->next = newnode;
            tail = newnode;
        } else
            head = tail = newnode;
    }

    void remove(int key) {
        if (!head)
            return;
        if (head->key == key) {
            node* temp = head;
            head = head->next;
            delete temp;
        } else {
            node* prev = head;
            node* curr = head->next;
            while (curr) {
                if (curr->key == key) {
                    prev->next = curr->next;
                    if (curr == tail)
                        tail = prev;
                    delete curr;
                    break;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }

    int front() {
        return head->key;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int, int> map;
    sll list;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (map.find(key) == map.end() || map[key] == -1)
            return -1;
        list.remove(key);
        list.append(key);
        return map[key];
    }

    void put(int key, int value) {
        if (map.find(key) != map.end() && map[key] != -1) {
            list.remove(key);
            map[key] = value;
            list.append(key);
        } else if (capacity == 0) {
            int key_to_be_removed = list.front();
            list.remove(key_to_be_removed);
            map[key_to_be_removed] = -1;
            map[key] = value;
            list.append(key);
        } else {
            map[key] = value;
            list.append(key);
            capacity--;
        }
    }
};