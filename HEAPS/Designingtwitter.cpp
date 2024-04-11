// LEETCODE -> Design Twitter
#include <bits/stdc++.h>
using namespace std;
class Twitter {
    unordered_map<int, vector<pair<int, int>>> feed;
    int time;
    unordered_map<int, unordered_map<int, bool>> followee;
public:
    Twitter() {
        time = 0;
    }
    void postTweet(int userId, int tweetId) {
        feed[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        vector<vector<pair<int, int>>> choices;
        for(auto itr : followee[userId]){
            if(itr.second and feed[itr.first].size() > 0) choices.push_back(feed[itr.first]);
        }
        if(feed[userId].size() > 0) choices.push_back(feed[userId]);
        priority_queue<vector<int>> pq; 
        for(int row = 0; row < choices.size(); row++){
            int n = choices[row].size();
            pq.push({choices[row][n-1].first, choices[row][n-1].second, row, n-1});
        }
        vector<int> res;
        for(int i = 1; i <= 10 && !pq.empty(); i++){
            auto top = pq.top(); pq.pop();
            res.push_back(top[1]);
            if(top[3] > 0)
                pq.push({choices[top[2]][top[3]-1].first, choices[top[2]][top[3]-1].second, top[2], top[3]-1});
        }
        return res;
    }
    void follow(int followerId, int followeeId) {
        followee[followerId][followeeId] = true;
    }
    void unfollow(int followerId, int followeeId) {
        followee[followerId][followeeId] = false;
    }
};