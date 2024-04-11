// Minions and Voting => 1830
// https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/MINVOTE
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>

vector<int> nse(vector<int>& arr) {
    vector<int> result(arr.size(), -1); 
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0 ; i--) {
        while (!st.empty() && arr[i] < arr[st.top()]) 
            st.pop();
        if(st.size() > 0) result[i] = st.top();
        st.push(i);
    }
    return result;
}

vector<int> nge(vector<int>& arr) {
    vector<int> result(arr.size(), -1); 
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0 ; i--) {
        while (!st.empty() && arr[i] > arr[st.top()]) 
            st.pop();
        if(st.size() > 0) result[i] = st.top();
        st.push(i);
    }
    return result;
}

vector<int> pge(vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) 
            st.pop();
        if(st.size() > 0)
            result[i] = st.top(); 

        st.push(i);
    }
    return result;
}

vector<int> pse(vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) 
            st.pop();
        if(st.size() > 0)
            result[i] = st.top(); 

        st.push(i);
    }
    return result;
}

vector<int> dijkstra(vector<vector<int>> &edge, int v, int e, int src)
{
	vector<vector<pair<int, int>>> adj(v);
	for(int i = 0; i < e; i++){
          adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
          adj[edge[i][1]].push_back({edge[i][0], edge[i][2]});
    }
	vector<int> distance(v, INT_MAX);
	distance[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
	pq.push({0, src});
	while(!pq.empty()){
		int dst = pq.top().first;
		int nd = pq.top().second;
		pq.pop();
		for(auto p : adj[nd]){
		    int nbr = p.first;
			int wt = p.second;
			if((dst + wt) < distance[nbr]){
				distance[nbr] = dst + wt;
				pq.push({dst + wt, nbr});
			}
		} 
	}
	return distance;
}

bool issorted(vector<int> &arr){
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}

void solve(){
    //* Write code here
    int n;
    cin >> n;
    vi arr(n), start(n,0), end(n,0);
    vll prefix(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    prefix[0] = arr[0];
    for(int i = 1; i < n; i++) prefix[i] = arr[i] + prefix[i-1];

    int low, high, mid;
    for(int i = 0; i < n; i++){
        // reach of a[i] towards left
        low = 0, high = i - 1;
        while(low < high){
            mid = (low + high)/2;
            if(prefix[i-1] - prefix[mid] > arr[i]) low = mid + 1;
            else high = mid;
        }
        start[low]++;
        // reach of a[i] towards right       
        low = i + 1, high = n - 1;
        while(low < high){
            mid = (low + high + 1)/2;
            if(prefix[mid-1] - prefix[i] > arr[i]) high = mid - 1;
            else low = mid;
        }
        end[high]++;
    }

    int counter = 0;
    for(int i = 0; i < n; i++){
        counter += start[i];
        cout << counter - 1 << " ";
        counter -= end[i];
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}