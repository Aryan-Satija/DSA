// queue using ll
#include <iostream>
using namespace std;
class Node {

public:
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

struct Queue {
  Node* front;
  Node* rear;
  void push(int);
  int pop();
  
  Queue() {
      front = rear = NULL;
  }
};
 
void Queue::push(int x) {
    Node* temp = new Node(x);
    if(front == NULL)
        front = rear = temp;
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int Queue::pop() {
    if(front == NULL)
        return -1;
    int data = front->data;
    Node* temp = front->next;
    front->next = NULL;
    front = temp;
    return data;
}