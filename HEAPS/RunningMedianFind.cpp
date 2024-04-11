// LEETCODE -> Find Median from Data Stream
#include <bits/stdc++.h>
using namespace std;
class MedianFinder {
public:
    int nonce;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {
        nonce = 0;
    }
    void addNum(int num) {
        nonce++;
        if(nonce == 1) maxHeap.push(num);
        else if(nonce&1){
            if(num < maxHeap.top()){
                int top = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(top);
            }
            else minHeap.push(num);
        }
        else{
            minHeap.push(num);
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
    }
    double findMedian() {
        if(nonce&1)
            return maxHeap.top();
        double a = maxHeap.top();
        maxHeap.pop();
        double b = maxHeap.top();
        maxHeap.push(int(a));
        return (a + b)/2.0;
    }
};
// 1. If all integer numbers from the stream are between 0 and 100, how would you optimize it?

// We can maintain an integer array of length 100 to store the count of each number along with a total count. Then, we can iterate over the array to find the middle value to get our median.

// Time and space complexity would be O(100) = O(1).

// 2. If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?

// In this case, we need an integer array of length 100 and a hashmap for these numbers that are not in [0,100].