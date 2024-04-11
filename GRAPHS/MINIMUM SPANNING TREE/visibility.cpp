// CODECHEF => 1816
// https://www.codechef.com/practice/course/4-star-difficulty-problems/DIFF1900/problems/JOKRBTMN


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

class disjointSet{
private:
    vector<int> rank, parent;
public:
    disjointSet(int v){
        // assuming nodes vary from 0 to v-1
        rank.resize(v, 0); 
        parent.resize(v);
        for(int i = 0; i < v; i++)
            parent[i] = i;
    }
    int UltimateParent(int n){
        if(parent[n] == n)
            return n;
        // path compression
        return parent[n] = UltimateParent(parent[n]);
    }
    void Union(int u, int v){
        int up_u = UltimateParent(u); 
        int up_v = UltimateParent(v);
        if(up_u == up_v)
            return;
        if(rank[up_u] < rank[up_v])
            parent[up_u] = up_v;
        else if(rank[up_v] < rank[up_u])
            parent[up_v] = up_u;
        else{
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }
    bool isSameComponent(int u, int v){
        return UltimateParent(u) == UltimateParent(v);
    }
};

void solve(){
    //* Write code here
    int col, n, l, k, col1, col2; 
    cin >> col >> n >> l;

    disjointSet ds(col + 1);
    
    for(int i = 0; i < n; i++){
        cin >> k;
        cin >> col1;
        for(int j = 1; j < k; j++){
            cin >> col2;
            ds.Union(col1, col2);
        }
    }

    vi arr(l);
    for(int i = 0; i < l; i++) cin >> arr[i];

    int segments = 1;
    for(int i = 1; i < l; i++){
        if(!ds.isSameComponent(arr[i], arr[i-1])) segments++;
    }

    cout << segments << endl;
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