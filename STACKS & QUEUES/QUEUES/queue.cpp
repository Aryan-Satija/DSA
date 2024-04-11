#include <bits/stdc++.h>
using namespace std;
class Queue 
{
	int front, rear;
	vector<int> arr;
public:
	Queue()
	{
		front = -1;
		rear = -1;
		arr.resize(100001);
	}
	void enqueue(int e)
	{
		if(front == -1)
		{
			front = rear = 0;
			arr[front] = e;				
		}
		else
			arr[++rear] = e;
		
	}
	int dequeue()
	{
		if(front == -1)
			return -1;
		int elem = arr[front];
		front++;
		if(front > rear)	
			front = rear = -1;
		return elem;
	}
};