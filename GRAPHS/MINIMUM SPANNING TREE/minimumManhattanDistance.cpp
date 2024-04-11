// LEETCDOE -> Min Cost to Connect All Points
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int manhattan_distance(int x1, int y1, int x2, int y2) {
        return abs(x2 - x1) + abs(y2 - y1);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // prims algorithm
        int v = points.size();

        vector<int> isVis(v, false);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        long long int res = 0;
        int remaining = v;
        while (remaining > 0) {
            int dist = pq.top()[0], node_index = pq.top()[1];
            int x = points[node_index][0], y = points[node_index][1];
            pq.pop();
            if (!isVis[node_index]) {
                res += dist;
                remaining--;
                isVis[node_index] = true;
                for (int nbr_index = 0; nbr_index < v; nbr_index++) {
                    int nx = points[nbr_index][0], ny = points[nbr_index][1];
                    if (!isVis[nbr_index]) {
                        pq.push({manhattan_distance(x, y, nx, ny), nbr_index});
                    }
                }
            }
        }
        return res;
    }
};
