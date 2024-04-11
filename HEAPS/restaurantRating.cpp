// CODECHEF -> Restaurant Rating -> 1851
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, size = 0, res = INT_MAX;
    cin >> n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    while(n--){
        int option;
        cin >> option;
        if(option == 1){
            size++;
            int num;
            cin >> num;
            if(size%3 == 0){
                if(num > res)
                    minHeap.push(num);
                else{
                    maxHeap.push(num);
                    res = maxHeap.top();
                    maxHeap.pop();
                    minHeap.push(res);
                }
            }
            else{
                if(num > res){
                    maxHeap.push(res);
                    minHeap.pop();
                    minHeap.push(num);
                    res = minHeap.top();
                }
                else
                    maxHeap.push(num);
            }
        }
        else{
            if(res == INT_MAX) cout << "No reviews yet" << endl;
            else cout << res << endl;
        }
    }
}
