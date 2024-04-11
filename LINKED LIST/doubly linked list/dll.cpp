#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node* next;
    node* prev;
    int data;
    node(int data)
    {
        this->data = data;
        next = prev = NULL;
    }
};
class dll
{
    node* head;
    node* tail;
public: 
    dll()
    {
        head = tail = NULL;
    }
    void insert(int data)
    {
        node* newNode = new node(data);
        if(head == NULL)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    // function overloadding
    void insert(int data, int index)
    {
        // ...DIY
    }
    void del(int index)
    {
        if(index == 0)
        {
            node* temp = head->next;
            head->next = temp->prev = NULL;
            head = temp;
            return;
        }
        node* curr = head, *prev = NULL;
        for(int i = 0; i < index; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = curr->prev = NULL;
    }
    void view()
    {
        node* iterator = head;
        cout << "X <--> ";
        while(iterator)
        {
            cout << iterator->data << " <--> ";
            iterator = iterator->next;
        }
        cout << "X" << endl;
    }

};
int main()
{
    dll ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(5);
    cout << endl << endl << endl << endl;
    ll.view();
    ll.del(2);
    ll.view();
    ll.del(0);
    ll.view();
    cout << endl << endl << endl << endl;
}