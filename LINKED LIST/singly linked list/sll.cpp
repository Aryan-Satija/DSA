#include <bits/stdc++.h>
using namespace std;
class node 
{
public: 
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class LinkedList
{
    node* head;
    node* tail;
    int size;
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int length()
    {
        return size;
    }
    void insert(int data)
    {
        node* newNode = new node(data);
        if(head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void insertFront(int data)
    {
        node* newNode = new node(data);
        if(head == NULL)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void view()
    {
        node* iterator = head;
        while(iterator != NULL)
        {
            cout << iterator->data << " -> ";
            iterator = iterator->next;
        }
        cout << "X" << endl;
    }
    void del(int index)
    {
        int currIndex = 0;
        node* prev = NULL, *curr = head;
        while(currIndex != index)
        {
            prev = curr;
            curr = curr->next;
            currIndex++;
        }
        if(prev == NULL)
        {
            node* temp = curr->next;
            curr->next = NULL;
            head = temp;
        }
        else
        {
            prev->next = curr->next;
            curr->next = NULL;
            curr = prev->next;
        }
    }
    void erase()
    {
        head = tail = NULL;
    }
};
int main()
{
    LinkedList sll;
    cout << endl << endl << endl << endl;
    sll.insertFront(1);
    sll.insertFront(2);
    sll.insertFront(3);
    sll.insertFront(4);
    sll.view();
    sll.del(1);
    sll.view();
    sll.del(2);
    sll.view();
    cout << endl << endl << endl << endl;
}