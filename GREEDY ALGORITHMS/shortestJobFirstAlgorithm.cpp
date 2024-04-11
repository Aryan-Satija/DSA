// CODING NINJAS -> SJF
#include <bits/stdc++.h>
using namespace std;
class comp {
    public:
       bool operator()(pair<int,int> a, pair<int, int> b){
           return a.second > b.second;
      }
};
float sjf(int n, vector<int> &arrivalTime, vector<int> &burstTime) {
    vector<pair<int, int>> jobs;
    for(int i = 0; i < n; i++)  
        jobs.push_back(make_pair(arrivalTime[i], burstTime[i]));
    sort(jobs.begin(), jobs.end());
    int time = jobs[0].first;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    int ptr = 0;
    for(; ptr < n and time == jobs[ptr].first; ptr++)
        pq.push(jobs[ptr]);
    float totalWaitingTime = 0;
    while(!pq.empty())
    {
        auto p = pq.top(); pq.pop();
        int arrival = p.first, burst = p.second;
        totalWaitingTime += (time - arrival);
        time += burst;
        for(; ptr < n and time >= jobs[ptr].first; ptr++)
            pq.push(jobs[ptr]);
    }
    return (totalWaitingTime/n);
}