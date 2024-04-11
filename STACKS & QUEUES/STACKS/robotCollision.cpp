// LEETCODE -> ROBOTS COLLISION
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // {position, index}
        int n =  positions.size();
        vector<vector<int>> robots;
        for(int i = 0; i < n; i++)
            robots.push_back({positions[i], i});
        
        
        sort(robots.begin(), robots.end());
        

        // {index}
        stack<int> st;
        for(auto robot : robots){
            if(st.empty() || directions[robot[1]] == 'R') st.push(robot[1]);
            else{
                bool flag = true;
                while(!st.empty()){
                    if(directions[st.top()] == 'R'){
                        if(healths[st.top()] == healths[robot[1]]){
                            flag = false;
                            healths[st.top()] = -1;
                            healths[robot[1]] = -1;
                            st.pop();
                            break;
                        }
                        else if(healths[st.top()] < healths[robot[1]]){
                            healths[st.top()] = -1;
                            healths[robot[1]]--; 
                            st.pop();
                        }
                        else{
                            flag = false;
                            healths[st.top()]--;
                            healths[robot[1]] = -1; 
                            break;
                        }
                    }
                    else
                        break;
                }
                if(flag)
                    st.push(robot[1]);
            }
        }

        vector<int> res;

        for(int i = 0; i < n; i++) {
            if(healths[i] != -1)
                res.push_back(healths[i]);
        }

        return res;
    }
};