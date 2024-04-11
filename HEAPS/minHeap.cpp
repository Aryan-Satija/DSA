// priority_queue are heaps!
// heaps are CBT (complete binary tree)!
// every subtree of a heap is a heap!
// if zero based indexing : left_child = (2*parent + 1) and right_child = (2*(parent + 1)) and parent = (childv - 1)/2
// if one based indexing : left_child = 2*parent and right_child = (2*parent + 1) and parent = child/2;
#include <bits/stdc++.h> 
using namespace std;
class minHeap {
    vector<int> arr;
    public:
    void heapify(int index)
    {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int smallest = index;
        if(left < arr.size() and arr[smallest] > arr[left])
            smallest = left;
        if(right < arr.size() and arr[smallest] > arr[right])
            smallest = right;
        if(smallest != index)
        {
            swap(arr[index], arr[smallest]);
            heapify(smallest);
        }
    }
    void insert(int val) {
        int i = arr.size();
        arr.push_back(val);
        while(i > 0)
        {
            int parent = (i-1)/2;
            if(arr[parent] > arr[i])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
                break;
        }    
    }
    void removeMin() {
        int i = arr.size() - 1;
        arr[0] = arr[i];
        arr.pop_back();
        heapify(0);
    }
    int minElement() {     
        return arr[0];
    }
};